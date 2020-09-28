#include <iostream>
#include <string>
#include <vector>
#include <memory>

void rvaluePrint(std::string&& str)
{
    std::cout << str << std::endl;
}

template <typename T>
T sum(T a) { return a; }

template <typename T, typename... Args>
T sum(T a, Args... args) {
    return a + sum(args...);
}

struct Test {
    Test(int a, int b, double d) : a(a), b(b), d(d) {}
    int a;
    int b;
    double d;
};

template <typename... Args>
Test make_test(Args&&... args) {
    return Test(std::forward<Args>(args)...);
}

template <typename... Args>
int make_sum(Args&&... args) {
    return sum(std::forward<Args>(args)...);
}


int main() {
    /*std::string str("Hello world!");

    rvaluePrint(std::string("Hello world!"));
    // rvaluePrint(str);                            // Error!
    std::vector<std::string> v;
    v.push_back(std::move(str));
    std::string str(std::string("Hello world!"));

    std::unique_ptr<int> pt;
    std::make_shared<int>(3);
    std::move();*/

    // ######## Variadic template ########
    std::cout << sum(2,2,2,2,2) << std::endl;
    std::cout << sum(2.6, 2.6, 2.56, 2.3, 2.3) << std::endl;
    std::cout << sum(std::string("Hello"), std::string(" world")) << std::endl;

    // ######## Perfect forwarding ########
    int a = 1;
    Test test = make_test(a, 1, 3.4);
    std::cout << test.a << std::endl;
    std::cout << test.d << std::endl;

    std::cout << make_sum(1, 2) << std::endl;



    std::cin.get();
    return 0;
}