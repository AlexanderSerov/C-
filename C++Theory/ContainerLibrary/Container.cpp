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
#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <span>

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

template <typename T, template <class _Ty, class _Alloc = allocator<_Ty>> class Container>
void PrintContainer(const Container<T>& cont)
{
    for (T n : cont)
        cout << n << " ";
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

struct Person
{
    int id;
    std::string name;
};


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
    /*stack<int, std::list<int>> st;
    for (auto n : {3,2,1})
        st.push(n);
    

    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }

    auto cont = st._Get_container();

    PrintContainer(cont);*/


 // priority_queue
    /*priority_queue<int,vector<int>,less<int>> pq{less<int>(),{5,8,3}};

    while (!pq.empty())
    {
        const auto& p = pq.top();
        cout << p << "\n";
        pq.pop();
    }

    std::vector<Person> persons{ {3, "Alex"}, {1, "Jon"}, {12, "Ben"} };
    auto comp = [](const Person& lhs, const Person& rhs) { return lhs.id < rhs.id; };
    std::priority_queue<Person, vector<Person>, decltype(comp)> persons_queue(comp, persons);

    while (!persons_queue.empty())
    {
        const auto& p = persons_queue.top();
        cout << p.id << " : " << p.name << "\n";
        persons_queue.pop();
    }*/


// ########## Heap operations ########## 
    /*std::vector<int> v{ 3, 1, 4, 1, 5, 9 };

    std::make_heap(v.begin(), v.end());

    v.push_back(7);
    std::push_heap(v.begin(), v.end());

    std::pop_heap(v.begin(), v.end());
    int largest = v.back();
    v.pop_back();

    cout << "is_heap: " << boolalpha << std::is_heap(v.begin(), v.end()) << endl;

    v.push_back(4);
    v.push_back(1);
    auto endIt = std::is_heap_until(v.begin(), v.end());

    sort_heap(v.begin(), v.end());
    PrintContainer(v);*/

   
// ########## UNORDERED CONTAINERS ##########
    const std::unordered_set<std::string> op_names_{ "Convolution", "Activation", "asdfasdf" };

    for (auto i : op_names_)
        cout << i << endl;
    cout << endl;

    std::unordered_map<std::string, bool> LegitimateUsers{ { {"Sam", true}, {"Alex", false}, {"Any", true} } };
    for (const auto& user : LegitimateUsers)
        cout << user.first << " : " << boolalpha << user.second << endl;
    cout << endl;

    cout << "LegitimateUsers summary:" << endl;
    cout << "bucket_count : " << LegitimateUsers.bucket_count() << endl;
    cout << "max_bucket_count : " << LegitimateUsers.max_bucket_count() << endl;
    cout << "Numeber of elements in \"Sam\" bucket : " << LegitimateUsers.bucket_size(LegitimateUsers.bucket("Sam")) << endl;
    cout << "Actual load_factor : " << LegitimateUsers.load_factor() << endl;
    cout << "max_load_factor : " << LegitimateUsers.max_load_factor() << endl;
    LegitimateUsers.reserve(11);
    cout << "bucket_count after reserving : " << LegitimateUsers.bucket_count() << endl;
    cout << "load_factor after reserving : " << LegitimateUsers.load_factor() << endl;   


// ########## SPAN ##########
    constexpr int a[] { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    std::span{a};
    std::vector<int> v {1, 2, 3};
    PrintContainer(v);


    cin.get();

    return 0;
}
