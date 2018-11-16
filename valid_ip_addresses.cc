#include <algorithm>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
#include "iostream"

using namespace std;

bool isValid(string s){
  if(s.length() > 3)
    return false;
  if(s.front() == '0' && s.length() > 1)
    return false;
  int val = stoi(s);
  return val <= 255 && val >= 0;
}

vector<string> GetValidIpAddress(const string& s) {
  /*  Return all possible valid IP addresses.
   *  This means we find how many ways there are of
   *  dividing the given string in 4 parts. That is
   *  inserting 3 periods. We need to generate all
   *  these valid IP addresses. Let's suppose
   *  the length of the given string is n. Then we
   *  can insert the periods in n-1 positions.
   *  So we can choose 3 such positions in nc3 ways.
   *  What if we have three loops ?
   *  One loop for the first period, second loop for the
   *  second period and third loop for the third period ?
   * */
  int n = s.length();
  vector<string> ans;
  for(int i=1; i<4 && i < n; i++){
    if(isValid(s.substr(0, i))){
      for(int j=1; i+j < n && j<4; j++){
        if(isValid(s.substr(i, j))) {
          for(int k=1; i+j+k < n && k<4; k++){
            if(isValid(s.substr(i+j, k)) && isValid(s.substr(i+j+k)))
              ans.emplace_back(s.substr(0, i) + '.' + s.substr(i, j) + '.' +
              s.substr(i+j, k) + '.' + s.substr(i+j+k));
          }
        }
      }
    }
  }
  return ans;
}
bool comp(vector<string> expected, vector<string> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "valid_ip_addresses.cc",
                         "valid_ip_addresses.tsv", &GetValidIpAddress, &comp,
                         param_names);
}
