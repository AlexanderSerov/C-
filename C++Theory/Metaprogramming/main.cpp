#include <iostream>
#include <chrono>
#include <array>
#include <type_traits>
#include <ciso646>
#include "omp.h"

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

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<>
char add<char>(char,char) = delete;


// one_of meta-function implementation
template<typename T, typename ... args>
struct one_of;

template<typename T>
struct one_of<T> : false_type {};

template<typename T, typename ... args>
struct one_of<T, T, args...> : true_type {};

template<typename T, typename U, typename ... args>
struct one_of<T, U, args...> : one_of<T, args...> {};

template<typename T, typename ... args>
inline constexpr bool one_of_v = one_of<T, args...>::value;

// Example of template alias
template<typename T, typename U>
using is_same_raw = is_same<remove_cv_t<T>, remove_cv_t<U>>;

template<typename T, typename U>
inline constexpr bool is_same_raw_v = is_same_raw<T,U>::value;



class A {};
class B {};

struct ALIGN{
    char a;
    char b;
    int c;
};


// is_base_of implementation
namespace details {
    template <typename Base> std::true_type is_base_of_test_func(const volatile Base*);
    template <typename Base> std::false_type is_base_of_test_func(const volatile void*);
    template <typename Base, typename Derived>
    using pre_is_base_of = decltype(is_base_of_test_func<Base>(std::declval<Derived*>()));

    // with <experimental/type_traits>:
    // template <typename Base, typename Derived>
    // using pre_is_base_of2 = std::experimental::detected_or_t<std::true_type, pre_is_base_of, Base, Derived>;
    template <typename Base, typename Derived, typename = void>
    struct pre_is_base_of2 : public std::true_type { };
    // note std::void_t is a C++17 feature
    template <typename Base, typename Derived>
    struct pre_is_base_of2<Base, Derived, std::void_t<pre_is_base_of<Base, Derived>>> :
            public pre_is_base_of<Base, Derived> { };
}

template <typename Base, typename Derived>
struct is_base_of :
        public std::conditional_t<
                std::is_class<Base>::value && std::is_class<Derived>::value,
                details::pre_is_base_of2<Base, Derived>,
                std::false_type
        > { };


// is_function truncated implementation
template<typename>
struct is_myfunction : false_type {};

template<typename Ret, typename... Args>
struct is_myfunction<Ret(Args...)> : true_type {};

template<typename T>
inline constexpr bool is_myfunction_v = is_myfunction<T>::value;

template<typename... Ts>
using TestType = auto(Ts...) -> decltype(print(std::declval<Ts>()...));


int main() {

// ############# Passing parameters to function as template parameters #############
    cout << print(3) << endl;
    cout << print<2>() << endl;
    cout << print<4>() << endl;

    static_assert(print(2) == 4);
    std::cout << std::is_function_v<decltype(f)> << '\n';

    // static_assert(print<2>() == 4);       Not legitimate!!! constexpr only

// ############# Compare template cycle over regular cycle #############

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    constexpr size_t N = 850;
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

    // one_of test
    static_assert(one_of_v<int, double, int>);
    static_assert(not one_of<int>());
    static_assert(not one_of_v<int, float, double>);
    static_assert(one_of_v<string, string>);

    std::false_type::value_type a((std::false_type()));
    cout << boolalpha << (bool)a << endl;

    // is_same_raw test
    static_assert(not is_same_raw_v<int, unsigned>);
    static_assert(is_same_raw_v<int, int>);
    static_assert(is_same_raw_v<string, string>);
    static_assert(not is_same_raw<string, array<int,5>>());

    static_assert(not ::is_base_of<A, B>());


    // is_myfunction test
    static_assert(is_myfunction_v<decltype(f)>);

    // !!! Eventually can't pass function overload to meta-function
    // static_assert(is_myfunction_v<decltype(print(declval<int>(declval<int>())()))>);
    static_assert(is_myfunction_v<TestType<int>>);

    // is_assignable test
    static_assert(is_assignable_v<int&, int>);
    static_assert(is_copy_assignable_v<int>);

    #pragma omp parallel
    {
        cout << "Hello world!(" << omp_get_num_threads() << ')' << endl;
    }


    // ### Data alignment ###
    static_assert((sizeof(int) == alignof(int)));
    static_assert(sizeof(char) == alignof(char));
    static_assert(sizeof(short) == alignof(short));
    static_assert(sizeof(long) == alignof(long));
    static_assert(!(sizeof(ALIGN) == alignof(ALIGN)));

    cout << "sizeof(ALIGN): " << sizeof(ALIGN) << endl << "alignof(ALIGN): " << alignof(ALIGN) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(int&): " << sizeof(int&) << endl;


    return 0;
}
