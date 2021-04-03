#include <iostream>
#include <type_traits>

using namespace std;

constexpr int print(int in) {
    return in + 2;
}

template<int in>
int print() {
    return in + 2;
}

int main() {

    cout << print(3) << endl;
    cout << print<2>() << endl;
    cout << 2 << endl;

    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);
    static_assert(print(2) == 4);

    // static_assert(print<2>() == 4);       Not legitimate!!! constexpr only

    std::cout << "Hello World!" << std::endl;

    return 0;
}
