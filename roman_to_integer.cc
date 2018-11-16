#include <string>
#include "test_framework/generic_test.h"
using std::string;

int getValue(char roman){
  if(roman == 'I')
    return 1;
  if(roman == 'V')
    return 5;
  if(roman == 'X')
    return 10;
  if(roman == 'L')
    return 50;
  if(roman == 'C')
    return 100;
  if(roman == 'D')
    return 500;
  if(roman == 'M')
    return 1000;
  return -1;
}

int RomanToInteger(const string& s) {
  int ans = 0;
  int n = s.length();
  for(int i=0; i<n; i++){
    if(s[i] == 'I' && i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X')){
      ans -= getValue(s[i]);
    }
    else{
      if(s[i] == 'X' && i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C')){
        ans -= getValue(s[i]);
      }
      else{
        if(s[i] == 'C' && i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M')){
          ans -= getValue(s[i]);
        }
        else
          ans += getValue(s[i]);
      }
    }

  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "roman_to_integer.cc", "roman_to_integer.tsv",
                         &RomanToInteger, DefaultComparator{}, param_names);
}
