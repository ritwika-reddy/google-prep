#include <string>
#include "test_framework/generic_test.h"

using namespace std;

string LookAndSay(int n) {
  string s = "1";
  if(n==1)
    return s;
  n--;
  while(n){
    string str = "";
    char ch = s[0];
    int count = 1;
    for(int i=1; i<s.length(); i++){
      if(s[i] == ch)
        count++;
      else{
        str += to_string(count);
        str += ch;
        ch = s[i];
        count = 1;
      }
    }
    str += to_string(count);
    str += ch;
    s = str;
    n--;
  }
  return s;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
