#include <string>
#include "test_framework/generic_test.h"
using std::string;

bool IsPalindrome(const string& s) {
  /*    We need to check if a string is a palindrome.
   *    Just check the beginning of the string with the
   *    end. I think we need to ignore punctuations and
   *    only consider alpha numeric characters.
   *    Also we should ignore the case of the characters
   *    I think.
   * */
  for(int i=0, j=s.length()-1; i<j; ){
      if(isalnum(s[i]) && isalnum(s[j])){
          if(tolower(s[i]) != tolower(s[j]))
              return false;
          i++;
          j--;
      }
      else{
          if(!isalnum(s[i]))
              i++;
          if(!isalnum(s[j]))
              j--;
      }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic_punctuation.cc",
                         "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                         DefaultComparator{}, param_names);
}
