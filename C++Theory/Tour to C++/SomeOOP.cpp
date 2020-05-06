#include <iostream>

using namespace std;

// Agenda:
// Name hiding
// Copy constructor

class A
{
protected:
    int data;
public:
    A(int data) : data(data){}

    int GetData(int a)
    {
        return data+a;
    }
};

class B : public A
{
public:
    B(int data) : A(data) {}

    int GetData()
    {
        return data;
    }
    using A::GetData;
};


void main()
{
    B b(2);
    cout << b.GetData(2) << endl;
}