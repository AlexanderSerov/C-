#include <iostream>
#include <typeinfo>
#include <chrono>

using namespace std;

void print(int* number)
{
    number++;
    cout << *number << endl;
}

int print(string number)
{
    cout << number << endl;
    return 1;
}

class Widget
{
public:
    static constexpr int data = 12;
};

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

int count_x(const char* str, char x)
{
    if (str == nullptr) return 0;

    int count = 0;
    for (;*str != 0; str++)
    {
        if (*str == x) count++;
    }
    return count;
}

void main(int argc, char const *argv[])
{ 
//Implicit type conversion playground
    /*bool flag = false;
    char symbol = 'a';
    short b = 3;

    cout << typeid(flag + symbol).name() << endl;
    cout << flag + symbol << endl;
    cout << typeid(b).name();*/

//constexpr
    /*cout << Widget::data << endl;

    int array[factorial(5)] {1,2,3,4,5};
    cout << sizeof(array) << endl;*/
    
//Cycle
    /*for (auto& str : {"Hello", "world!", "How", "are", "you?"})
        cout << str << ' ';
    cout << endl;*/

//Time mesurement
    /*auto stop = chrono::high_resolution_clock::now();
    auto start = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << endl;*/

//Const pointers
    /*int num = 3;
    const int * p1 = &num;
    int * const p2 = &num;
    int * p3 = &num;
    const int * const p4 = &num;
    print(p2);*/

//Describe each operation with terms[Assignment,Initialization,Declaration]
    /*int a;
    a = 3;
    int b = 4;*/

//nullptr
    /*char* str {"Hello world!"};   //What is difference here?
    char str[] {"Hello world!"};
    char* str = nullptr;
    cout << count_x(str, 'l') << endl;*/
}