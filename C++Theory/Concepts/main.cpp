#include <concepts>
#include <iostream>
#include <string>
#include <initializer_list>
#include <iterator>
#include <vector>

using namespace std;


template<typename T> requires (std::is_arithmetic_v<T> && !std::is_same_v<T, char>)
__attribute__((deprecated)) T add(T a, T b) {
  return a + b;
}


// The old C++11 way
/*template<>
char add(char,char) = delete;
template<>
std::string add(std::string, std::string) = delete; */


int main() {

  using std::operator""s;
  cout << "Addition: " << add (2, 3) << endl;
  cout << "Addition: " << add (2.3, 3.6) << endl;
//   cout << "Addition: " << add ('a', 'a') << endl;			// Not meet constains
//  cout << "Addition: " << add ("sdfsd"s, "sdfsdf"s) << endl;





  return 0;
}
