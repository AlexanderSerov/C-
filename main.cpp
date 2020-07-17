// LearningC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


int main()
{
    string buff{ "Hello world" };

    // I/O characters from console
    /*char buff;
    cin.get(buff);
    while (buff != '\n')
    // for (int i(0); i < 4; i++)
    {
        cout.put(buff);
        cin.get(buff);
    }*/

    /*string str;
    for (int i(0); i < 2; i++)
    {
        getline(cin, str);
        cout.write(str.data(), str.size());
        cout.put('\n');
    }*/

    // I/O lines from console 
    /*char buff[10];
    for (int i(0); i < 2; i++)
    {
        cin.getline(buff, 10);
        cout.write(buff, 10);
        cout.put('\n');
    }*/

    // Working with istringstream
    /*istringstream input{ "  Who knows; how long I’ve; loved you \n\
                            You know; I love you still; \n\
                            Will I wait a lonely; lifetime \n\
                            If you want me to, I will \n"   };

    // cout << input.str();
    cout << input.tellg() << endl;
    for (string buff; getline(input, buff, ';');)
    {
        // cout << input.tellg() << endl;
        input.seekg(-19, ios::end);
        cout << buff << endl;
    }
    cout << input.tellg() << endl;*/

    /*string str{ "Hello world!!" };
    for (const auto& ch : str) {
        cout << ch;        
    }
    cout << endl;*/

    // Error streams
    /*cerr << buff << endl;
    clog << buff << endl;
    cout << "Hello world!!" << endl;
    cout << cout.tellp() << endl;
    cerr.tellp();*/

    // Stream error handling
    istringstream inStr{"Hello worl"};
    ifstream in("df.df");
    cout << ((in) ? "true" : "false") << endl;
    cout << boolalpha << inStr.good() << endl;
    cout << boolalpha << in.bad() << endl;

    char c;
    while (inStr.eof() == false) {
        inStr.get(c);
        cout.put(c);
    }
        

    

    system("pause");
    return 0;

}