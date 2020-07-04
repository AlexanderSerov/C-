#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class SmartPointer
{
    T* ptr;
public:
    SmartPointer(T* pointer) : ptr(pointer) {}
    ~SmartPointer() {delete ptr;}
    T& operator*() {return *ptr;}
};

template <typename T>
void Revese(T first, T last)
{
    while ((first!=last)&&(first!=--last))
    {
        swap(*first,*last);
        first++;
    }
}

template <typename T>
void PrintContainer(const forward_list<T>& cont)
{
    for (T n : cont)
        cout << n;
    cout << endl;
}

template <typename T>
void PrintSet(const set<T>& S)
{
    for (auto& n : S)
        cout << n << " ";
    cout << endl;
}

template <typename T>
void PrintSet(const multiset<T>& S)
{
    for (auto& n : S)
        cout << n << " ";
    cout << endl;
}

template <typename KEY, typename T>
void PrintMap(const map<KEY,T>& M)
{
    for (auto& m : M)
        cout << m.first << " : " << m.second << endl;
}


int main()
{
// For remind how STL containers work look at Complexity table and CppReference methods
// Smart pointers (unique_ptr, weak_ptr, shared_ptr)
    /*SmartPointer<int> ptr = new int(3);
    cout << *ptr << endl;*/

    //unique_ptr<int> ptr(new int(3));
    //unique_ptr<int> ptr = make_unique<int>(3);
    //auto sh_ptr = make_shared<int>(3);
    //cout << *sh_ptr << endl;

// Iterators
    /*vector<int> numbers {2,3,7,4,9,8,4};
    auto it = numbers.begin();
    cout << *it << endl;
    it++;
    cout << *it << endl;
    
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it;

    numbers.insert(numbers.begin()+4,{5,6,7,8});
    cout << endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it;

    numbers.erase(numbers.end()-2, numbers.end());

    cout << endl;
    for (auto n : numbers)
        cout << n;

    const int size = 7;
    int arr[size] {1,2,3,4,5,6,7};
    Revese(arr,arr+size);  // Inplace revese array or container
    cout << endl;

    cout << endl << *it << endl;
    advance(it,3);
    cout << *it << endl;

// Initialization list/Uniform initialization
    initializer_list<int> l {1,2,3};
    numbers.insert(numbers.end(), l);

    cout << endl;
    for (auto n : numbers)
        cout << n;*/

// std::list
    vector<int> numbers {4,7,3,7,9,3,5,5,5,9,9};
    list<int> l (numbers.begin(), numbers.end());
    list<int> l2 {5,8,4,6,9};

    /*l.sort();
    l2.sort();

    l.merge(l2);

    for (int n : l)
        cout << n;
    cout << endl;

    for (int n : l2)
        cout << n;
    cout << endl;

    l2.splice(l2.begin(), l, next(l.begin(), 2), next(l.begin(), 5));
    l.unique();

    for (int n : l)
        cout << n;
    cout << endl;

    for (int n : l2)
        cout << n;
    cout << endl;*/

// Difference between it++ and ++it where it == iterator
// std::forward_list
    //forward_list<int> fl {4,7,3,7,9,3,5,5,5,9,9};

    /*PrintContainer(fl);

    fl.insert_after(fl.before_begin(), 7);

    PrintContainer(fl);*/

// Iterator invalidation
    /*for (auto it=numbers.begin();it!=numbers.end();it++) // Bad design
        if ((*it) == 7)
            numbers.push_back(-1);*/

    /*for (int i(0); i != numbers.size(); i++)
        if (numbers[i] == 7)
            numbers.push_back(3);

    for (auto it=numbers.begin(); it!=numbers.end(); ++it) 
        cout << (*it) << " ";
    cout << endl;

    numbers.erase(remove(numbers.begin(), numbers.end(), 7),numbers.end());

    for (auto n : numbers)
        cout << n << " ";
    cout << endl;*/

// std:array
    /*array<char, 6> arr {"Hello"};
    arr.fill('G');
    array<char, 6> arr2;

    arr2 = arr;

    for (auto c : arr2)
        cout << c;*/

// Container comparison
    /*array<int, 6> arr {6,7,7};
    array<int, 6> arr2 {6,7,6};
    
    cout << (arr < arr2);*/

// std:deque
    // deque<int> dq {4,7,3,7,9,3,5,5,5,9,9};

// std::set and std::multiset
    /*set<string> SetS {"ssd","gc","taf"};
    set<int> Set {4,8,2,5};
    set<int> Set2 {1,9};

    PrintSet(Set);
    Set.insert(7);
    PrintSet(Set);

    Set.insert(Set2.extract(Set2.begin()));
    PrintSet(Set);
    PrintSet(Set2);

    multiset<int> ms (Set.begin(), Set.end());
    ms.insert(5);
    ms.insert(5);
    PrintSet(ms);

    auto res = ms.equal_range(5);
    cout << *get<0>(res) << " " << *get<1>(res) << endl;
    ms.erase(get<0>(res), get<1>(res));
    PrintSet(ms);*/

// std::map and std::multimap
    /*map<int,string> mp {{3, "dog"s}};

    mp.insert(make_pair(1,"book"s));
    mp.emplace(2,"cat"s);
    mp[4] = "monitor";
    PrintMap(mp);

    cout << mp[3] << endl;


    multimap<int,string> mmp (mp.begin(), mp.end());
    mmp.emplace(2,"fox"s);
    for (auto& p : mmp)
        cout << p.first << " : " << p.second << endl;

    cout << mmp.find(2)->second << endl;*/

// std::stack
    stack<int> st;
    for (auto n : {3,2,1})
        st.push(n);
    

    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
