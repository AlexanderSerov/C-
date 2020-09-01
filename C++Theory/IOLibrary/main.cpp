#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <thread>

using namespace std;


class Point3d
{
public:
    Point3d() : x(-1), y(-1), z(-1) {}
    explicit Point3d(double x, double y, double z) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream& out, Point3d& point);
    friend istream& operator>>(istream& in, Point3d& point);
private:
    double x;
    double y;
    double z;
};

ostream& operator<<(ostream& os, Point3d& point)
{
    os << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

istream& operator>>(istream& in, Point3d& point)
{
    in >> point.x;
    in >> point.y;
    in >> point.z;
    return in;
}

ostream & fl(ostream & os)
{
    os << "Hello world!";
    return os;
}

void func(Point3d p1, Point3d p2)
{
    cout << p1 << endl;
    cout << p2 << endl;
}

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

int main(int argc, char** argv)
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
    istringstream input{ "  Who knows; how long I have; loved you \n\
                            You know; I love you still; \n\
                            Will I wait a lonely; lifetime \n\
                            If you want me to, I will\n" };

    // cout << input.str();
    /*cout << input.tellg() << endl;
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
    /*istringstream inStr{"Hello world"};
    ifstream in("df.df");
    cout << ((in) ? "true" : "false") << endl;
    cout << boolalpha << inStr.good() << endl;
    cout << boolalpha << in.bad() << endl;

    char c;
    while (inStr.eof() == false) {
        inStr.get(c);
        cout.put(c);
    }

    string buffer;
    while(input >> buffer)
        cout << buffer <<endl;*/

        // Some monipulation with stream
        /*ostringstream output;
        output << input.str();
        cout << output.str();*/

        // Multidimentional arryas
        /*int mat[10][5];
        for (int i(0); i<10; i++)
            for (int j(0); j<5; j++)
                mat[i][j] = i+j+1;

        for (int i(0); i<10; i++) {
            for (int j(0); j<5; j++)
                cout << mat[i][j] << '\t';
            cout << endl;
        }

        int anotherMat[3][3] {{1,2,3},{4,5,6},{7,8,9}};
        cout << *(anotherMat[2]);*/

        // Stream operators for user-defined class
        /*Point3d a(1.5,2.5,3.5);
        Point3d b(2.2,3.4,5.6);

        cout << a << endl;
        cout << b << endl;*/

    /*string pointsPath;
    pointsPath = argc > 1 ? argv[1] : "Points.txt";
    ifstream pointsFile(pointsPath);
    if (!pointsFile.is_open()) {
        cout << "Failed to open Points.txt" << endl;
        return -1;
    }

    vector<Point3d> points;
    while (!pointsFile.eof())
    {
        Point3d point;
        pointsFile >> point;
        points.push_back(point);
    }

    for (auto& p : points)
        cout << p << endl;*/

    
    // Redefine stream manupulator 
    // cout << fl << endl;

    // MANIPULATORS
    /*cout << boolalpha << true << noboolalpha << endl;
    cout << true;

    // You can see difference with flushes only on Linux machine.
    for (int i(0); i < 5; i++)
    {
        cout << i << ' ' << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }*/

    /*cout << setbase(16) << showbase << 110 << endl;

    cout << setbase(16) << showbase << left << setfill('*');
    cout << setw(10) << 25 << setw(10) << 13 << setw(10) << 45 << endl;

    double pi = 3.14334563573463467567;
    cout << setprecision(15) << pi << endl;*/

    /*stringstream ss;
    cout << quoted("Hello \"world\"") << endl;
    ss << quoted("Hello \"world\"");
    string str;
    ss >> quoted(str);
    cout << str << endl;*/

    /*string TextPath = argc > 1 ? argv[1] : "Text.txt";
    ifstream pointsFile(TextPath);
    if (!pointsFile.is_open()) {
        cout << "Failed to open Text.txt" << endl;
        return -1;
    }

    cout << pointsFile.rdbuf();*/

    /*istringstream ss{"1.55"};
    long double money;
    ss.imbue(std::locale("ru_RU.UTF-8"));
    ss >> get_money(money, true);
    cout << money << endl;*/

    // ERROR HANDLING
    /*string str;
    std::ifstream f("doesn't exist");
    try {
        f.exceptions(f.failbit);
    }
    catch (const std::ios_base::failure& ex) {
        cout << ex.code() << endl;
    }
    catch (...) {
        cout << "Catch all!" << endl;
    }*/

    // ios_base;

    vector<int> v(3);
    cout << v[1] << endl;

    func(Point3d{ 1,2,3 }, Point3d{ 3,2,1 });

    cin.get();
    return 0;
}