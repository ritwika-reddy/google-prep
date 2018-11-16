#include <string>
#include "test_framework/generic_test.h"
using std::string;

string SnakeString(const string& s) {
  int n = s.length();
  string stru = "", strm = "", strl = "";
  for(int i=0; i<n; i++){
    if(i%2 == 0)
      strm += s[i];
    if(i%4 == 1)
      stru += s[i];
    if(i%4 == 3)
      strl += s[i];
  }
  return stru+strm+strl;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "snake_string.cc", "snake_string.tsv",
                         &SnakeString, DefaultComparator{}, param_names);
}
