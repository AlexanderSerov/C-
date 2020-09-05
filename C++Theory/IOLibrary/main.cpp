#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <thread>
#include <algorithm>

using namespace std;


class Point3d
{
public:
    Point3d() : x(-1), y(-1), z(-1) {}
    explicit Point3d(double x, double y, double z) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream& out, const Point3d& point);
    friend istream& operator>>(istream& in, Point3d& point);
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& os, const Point3d& point)
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

struct BinaryProfile {
    int age;
    bool male;
    float weight;
    string FullName;
    friend ostream& operator<<(ostream& os, BinaryProfile& bp);
    friend istream& operator>>(istream& in, BinaryProfile& bp);
};

ostream& operator<<(ostream& os, BinaryProfile& bp)
{
    size_t len = bp.FullName.size();
    os.write((char*)&bp.age, sizeof(bp.age));
    os.write((char*)&bp.male, sizeof(bp.male));
    os.write((char*)&bp.weight, sizeof(bp.weight));
    os.write((char*)&len, sizeof(len));
    os.write(bp.FullName.data(), bp.FullName.size());
    return os << flush;
}

istream& operator>>(istream& in, BinaryProfile& bp)
{
    in.read((char*)&bp.age, sizeof(bp.age));
    in.read((char*)&bp.male, sizeof(bp.male));
    in.read((char*)&bp.weight, sizeof(bp.weight));
    size_t len;
    in.read((char*)&len, sizeof(len));
    char* temp = new char[len + 1];
    in.read(temp, len);
    temp[len] = '\0';
    bp.FullName = temp;
    delete[] temp;
    return in;
}

struct Ass
{
    int data1;
    double data2;
};


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

    vector<Point3d> points((std::istream_iterator<Point3d>(pointsFile)), std::istream_iterator<Point3d>());

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


    // BINARY READ/WRITE
    
    BinaryProfile Peter;
    Peter.age = 28;
    Peter.male = true;
    Peter.weight = 65.3;
    Peter.FullName = "Peter Yan";

    /*ofstream of("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Binary");
    if (!of.is_open()) {
        cout << "Failed to open" << endl;
        cin.get();
        return -1;
    }

    size_t len = Peter.FullName.size();
    of.write((char*)&Peter.age, sizeof(Peter.age));
    of.write((char*)&Peter.male, sizeof(Peter.male));
    of.write((char*)&Peter.weight, sizeof(Peter.weight));
    of.write((char*)&len, sizeof(len));
    of.write(Peter.FullName.data(), Peter.FullName.size());*/

    /*BinaryProfile Peter;

    ifstream iff("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Binary");
    if (!iff.is_open()) {
        cout << "Failed to open" << endl;
        cin.get();
        return -1;
    }
    
    iff.read((char*)&Peter.age, sizeof(Peter.age));
    iff.read((char*)&Peter.male, sizeof(Peter.male));
    iff.read((char*)&Peter.weight, sizeof(Peter.weight));
    size_t len;
    iff.read((char*)&len, sizeof(len));
    char* temp = new char[len+1];
    iff.read(temp, len);
    temp[len] = '\0';
    Peter.FullName = temp;
    delete[] temp;*/

    /*BinaryProfile Peter;
    Peter.age = 28;
    Peter.male = true;
    Peter.weight = 65.3;
    Peter.FullName = "Peter Yan";

    ofstream of("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Binary");
    if (!of.is_open()) {
        cout << "Failed to open" << endl;
        cin.get();
        return -1;
    }

    of << Peter;
    of.close();

    ifstream iff("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Binary");
    BinaryProfile Peter2;
    iff >> Peter2;
    iff.close();*/

    // Reading and Writing intire object.
    // Only works with trivial data.
    /*Ass A;
    A.data1 = 4;
    A.data2 = 6.7;
    Ass B;

    fstream fs("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Binary", ios::in | ios::out | ios::binary);
    fs.write((char*)&A, sizeof(Ass));
    fs.flush();
    fs.seekg(0);
    fs.read((char*)&B, sizeof(Ass));*/

    // ### stream_iterator ###  You can use stream with any algorighm
    // ifstream pointsFile("D:/Repos/CPlusPlus/C++Theory/IOLibrary/Points.txt");

    // vector<Point3d> points;
    /*std::copy(std::istream_iterator<Point3d>(pointsFile),
        std::istream_iterator<Point3d>(),
        std::back_inserter(points));

    /*for (auto& p : points)
        cout << p << endl;*/

    // Print only Points which coordinates less than 10
    /*ostringstream oss;
    std::remove_copy_if(points.begin(), points.end(),
        std::ostream_iterator<Point3d>(oss, "\n"), [](Point3d& point) 
        {
            return point.x >= 10 || point.y >= 10 || point.z >= 10;
        });
    
    cout << oss.str();*/

    // The above code in less lines
    /*std::remove_copy_if(std::istream_iterator<Point3d>(pointsFile),
        std::istream_iterator<Point3d>(),
        std::ostream_iterator<Point3d>(std::cout, "\n"), [](const Point3d& point)
    {
        return point.x >= 10 || point.y >= 10 || point.z >= 10;
    });*/

    // Work manually with iterators
    /*auto it = std::istream_iterator<Point3d>(pointsFile);
    it++;
    cout << *it << endl;*/




    cin.get();
    return 0;
}