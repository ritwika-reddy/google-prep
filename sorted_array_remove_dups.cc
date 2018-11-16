#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using namespace std;
// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>* A_ptr) {
  /*
   * Remove duplicates and shift all the elements
   * to the left to fill the gaps.
   * */

  int n = A_ptr->size();
  vector<int> &A = *A_ptr;
  int i=0, j=0;
  if(n == 0)
    return 0;

//  int prev = A[i];
//  while(j < n){
//    while(A[j] == prev)
//      j++;
//    if(j < n){
//      A[i++] = prev;
//      prev = A[j++];
//    }
//  }
//  A[i++] = prev;
  for(int j=1; j<n; j++){
    if(A[j] != A[i])
      A[++i] = A[j];
  }
  return i+1;
}
vector<int> DeleteDuplicatesWrapper(TimedExecutor& executor, vector<int> A) {
  int end = executor.Run([&] { return DeleteDuplicates(&A); });
  A.resize(end);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "sorted_array_remove_dups.cc", "sorted_array_remove_dups.tsv",
      &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
}
