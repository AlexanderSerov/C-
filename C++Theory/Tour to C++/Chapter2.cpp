#include <iostream>
#include <variant>

using namespace std;

class cl1 
{
public:
    int val;
    cl1(): val(1) {}
};

class cl2
{
public:
    int val;
    cl2(): val(2) {}
};

void PrintVersionOfStandard()
{
    // For __cplusplus macro return correct macro, you need pass /Zc:__cplusplus option to compiler
    // Pass /std:c++17 parameter to compiler for changing standard
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
}

enum Color: int {red, green, blue};
enum class Advanced_Color {red, green, blue, purple, brown};

void PrintColor(Color color)
{
    switch(color)
    {
        case Color::red  : cout << "red\n";   break;
        case Color::green: cout << "green\n"; break;
        case Color::blue : cout << "blue\n";  break;
    }
}

void PrintAdvancedColor(Advanced_Color ad_color)
{
    switch(ad_color)
    {
        case Advanced_Color::red  : cout << "red\n";   break;
        case Advanced_Color::green: cout << "green\n"; break;
        case Advanced_Color::blue : cout << "blue\n";  break;
        case Advanced_Color::purple : cout << "purple\n";  break;
        case Advanced_Color::brown : cout << "brown\n";  break;
    }
}

std::ostream& operator<<(std::ostream& os, Advanced_Color c)
{
    switch(c)
    {
        case Advanced_Color::red   : os << "red";    break;
        case Advanced_Color::green : os << "green";  break;
        case Advanced_Color::blue  : os << "blue";   break;
        case Advanced_Color::purple  : os << "purple";   break;
        case Advanced_Color::brown  : os << "brown";   break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}

struct SampleVisitor
{
    void operator()(int i)
    {
        cout << "int: " << i << endl;
    }
    void operator()(double i)
    {
        cout << "double: " << i << endl;
    }
    void operator()(const string& i)
    {
        cout << "string: " << i << endl;
    }
};

void main()
{
// Return int& operator[]{} for reading and writing. 
// prefix/postfix perator oveloading
    /*int x = 0;
    int y = 0;
    x = y++;        // x = 0, y = 1

    void operator ++()      //prefix increment ++a
    void operator ++(int)   //postfix increment a++*/
// Enum in Modern C++
    /*Color color = static_cast<Color>(1);
    int t = red;                    // OK
    //int g = Advanced_Color::brown;  // Error
    int l = static_cast<int>(Advanced_Color::brown);
    Advanced_Color ad_color = Advanced_Color::purple;

    PrintColor(red);
    PrintAdvancedColor(static_cast<Advanced_Color>('1'));
    PrintAdvancedColor(Advanced_Color::purple);

    //Initializin with direct list {}
    Advanced_Color ad_color2 {'d'};
    PrintAdvancedColor(ad_color2);

    //Enum operator<< overvoading fro returning string.
    cout << Advanced_Color::brown << endl;*/

// How float datatype stored in memory?
    // cout << sizeof(float) << endl;
// variant STL
    /*variant<int,double,string> MyVariant;
    cout << "index = " << MyVariant.index() << endl;

    static_assert(std::variant_size_v<decltype(MyVariant)> == 3);

    visit(SampleVisitor{},MyVariant);
    
    MyVariant = 3;
    cout << "index = " << MyVariant.index() << endl;
    MyVariant = 5.323;
    cout << "index = " << MyVariant.index() << endl;
    MyVariant = "Hello world";
    cout << "index = " << MyVariant.index() << endl;

    if (const auto ptr = get_if<int>(&MyVariant); ptr)
        cout << "Value: " << *ptr << endl;
    if (const auto ptr = get_if<double>(&MyVariant); ptr)
        cout << "Value: " << *ptr << endl;
    if (const auto ptr = get_if<string>(&MyVariant); ptr)
        cout << "Value: " << *ptr << endl;

    if (holds_alternative<int>(MyVariant))
        cout << "Variant holds value double" << endl;
    if (holds_alternative<double>(MyVariant))
        cout << "Variant holds value int" << endl;
    if (holds_alternative<string>(MyVariant))
        cout << "Variant holds value string" << endl;

    try
    {
        auto f = get<int>(MyVariant);
    }
    catch(const bad_variant_access& ex)
    {
        cerr << ex.what() << '\n';
    }

    visit(SampleVisitor{},MyVariant);
    MyVariant = 5.3124;
    visit(SampleVisitor{},MyVariant);
    MyVariant = "Looking for better";
    visit(SampleVisitor{},MyVariant);*/

// List initialization
    /*int a {4.3254};   // List intialization prohibit harrowong conversion
    int x2 = 7.9; // if val==7.9, x2 becomes 7 (bad)
    char c2 = 1025; // if val2==1025, c2 becomes 1 (bad)
    int x3 {7.9}; // error: possible truncation (good)
    char c3 {1045}; // error: possible narrowing (good)
    char c4 {24}; // OK: 24 can be represented exactly as a char (good)
    char c5 {264}; // error (assuming 8-bit chars): 264 cannot be 
                   // represented as a char (good)
    int x4 {2.0}; // error: no double to int value conversion (good)
    
    rectangle w {origin(), extents()};*/
}