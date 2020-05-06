#include <iostream>
#include <regex>

using namespace std;

string compose(const string& name, const char* domain)
{
    return name + '@' + domain;
}

string concatenate(string_view sv1, string_view sv2)
{
    string result;
    result.resize(sv1.length()+sv2.length());

    char* p = &result[0];
    for (char c : sv1)
        *p++ = c;
    
    sv2.copy(p,sv2.length());

    return result;

}

bool show_matches(string_view input, string_view pattern)
{
    regex reg {pattern.data()};

    return regex_match(input.data(), reg);
}

void main()
{
// string
    /*string EmailList;
    EmailList += compose("cah4ec33", "yandex.ru") + '\n'; 
    EmailList += compose("can4ec333"s, "gmail.com") + '\n';

    cout << EmailList;*/

// Allocator
    /*allocator<int> MyAlloc;

    int* ptr = MyAlloc.allocate(1);
    MyAlloc.construct(ptr,7);
    cout << *ptr << endl;
    MyAlloc.deallocate(ptr,1);*/

// string_view
    //cout << concatenate("Hello "sv, "world"sv) << endl;

// Regular expressions
    string pat {R"(A{3}B{2,4}C*)"};
    string str {"AABBC"};

    cout << "Is string match the pattern: " << (show_matches(str, pat) ? "Yes" : "No") << endl;

    string input;
    regex Double ({R"([-+]?\d*\.?\d*)"});

    while(true)
	{
 		cout<<"Give me an double!"<<endl;
		cin>>input;
 		if(!cin) break;
		//Exit when the user inputs q
 		if(input=="q")
			break;
		if(regex_match(input,Double))
			cout<<"double"<<endl;
		else
	    {
			cout<<"Invalid input"<<endl;
	    }
 	}
}

