#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "iostream"

using namespace std;

string IntToString(int x) {
  /*   Convert given integer to a string.
   *  We cannot use library functions like stoi in C++.
   *  Maybe we can use something else in C++ ?
   * */
  if(x==0)
      return "0";
  bool neg = (x<0) ? true : false;
  string s = "";
  while(x){
      char c = '0' + abs(x%10);
      x /= 10;
      // s = c + s; // Instead of prepending, just append and finally return the reversed string.
      s += c;
  }
  s = neg ? s + '-' : s;
  return {rbegin(s), rend(s)};
}
int StringToInt(const string& s) {
  int x = 0;
  int n = s.length();
  if(n == 0 )
      return 0;
  bool neg = false;
  int i=0;
  if(s[0] == '-'){
      neg = true;
      i++;
  }
  for(; i<n; i++)
      x = ((x*10) + (s[i]-'0'));
  return neg ? -1*x : x;
}
void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
