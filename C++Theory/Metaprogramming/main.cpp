#include <iostream>
#include <chrono>
#include <array>
#include <type_traits>

using namespace std;

constexpr int print(int in) {
    return in + 2;
}

template<int in>
int print() {
    return in + 2;
}

int f();

template<typename T, std::size_t N>
struct DotProductT {
    static inline T result(const T* a, const T* b) {
        return *a * *b  +  DotProductT<T, N-1>::result(a+1,b+1);
    }
};

// partial specialization as end criteria
template<typename T>
struct DotProductT<T, 0> {
    static inline T result(const T*, const  T*) {
        return T(0);
    }
};

template<typename T, std::size_t N>
auto dotProductMeta(std::array<T, N> const& x,
                std::array<T, N> const& y)
{
    return DotProductT<T, N>::result(&(*x.begin()), &(*y.begin()));
}

template<typename T, std::size_t N>
auto dotProduct(std::array<T, N> const& x,
                std::array<T, N> const& y)
{
    T result{};
    for (std::size_t k = 0; k<N; ++k) {
        result += x[k]*y[k];
    }
    return result;
}

int main() {

// ############# Passing parameters to function as template parameters #############
    cout << print(3) << endl;
    cout << print<2>() << endl;
    cout << print<4>() << endl;

    static_assert(print(2) == 4);
    std::cout << std::is_function<decltype(f)>::value << '\n';

    // static_assert(print<2>() == 4);       Not legitimate!!! constexpr only

// ############# Compare template cycle over regular cycle #############

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    const size_t N = 850;
    std::array<double, N> x;
    std::array<double, N> y;

    for (int i(0); i < N; i++) {
        x[i] = y[i] = double (i);
    }

    auto t1 = high_resolution_clock::now();
    cout << "Regular dot product: " << dotProduct(x, y) << endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Time: " << ms_double.count() << endl;

    t1 = high_resolution_clock::now();
    cout << "Meta dot product: " << dotProductMeta<double, N>(x, y) << endl;
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Time: " << ms_double.count() << endl;

    return 0;
}
