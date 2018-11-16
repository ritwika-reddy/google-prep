#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using namespace std;
string Decoding(const string &s) {
  string str = "";
  int n = s.length();
  if(n==0)
    return str;
  int count;
  for(int i=0; i<n; i++){
    if(isdigit(s[i])){
      int j = 1;
      while(isdigit(s[i+j]))
        j++;
      count = stoi(s.substr(i,j));
      while(count--)
        str += s[i+j];
      i = i+j;
    }
  }
  return str;
}

string Encoding(const string &s) {
  string str = "";
  int n = s.length();
  if(n==0)
    return str;
  char ch = s[0];
  int count=1;
  for(int i=1; i<n; i++){
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
  return str;
}

void RleTester(const string &encoded, const string &decoded) {
  if (Decoding(encoded) != decoded) {
    throw TestFailure("Decoding failed");
  }
  if (Encoding(decoded) != encoded) {
    throw TestFailure("Encoding failed");
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"encoded", "decoded"};
  return GenericTestMain(args, "run_length_compression.cc",
                         "run_length_compression.tsv", &RleTester,
                         DefaultComparator{}, param_names);
}
