#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  /* Int as array increment.
   * Basically we need to perform addition.
   * Right ?
   * */

  vector<int> ans;
  bool carry = true;
  for(int i=A.size()-1; i>=0; i--){
      if(carry){
          if(A[i]+1 == 10)
              carry = true;
          else
              carry = false;
          A[i] = (A[i]+1)%10;
      }
      else
          break;
  }
  if(carry)
      A.insert(A.begin(), 1);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
