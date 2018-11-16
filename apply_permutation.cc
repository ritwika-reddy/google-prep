#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {

  vector<int> &A = *A_ptr;
  vector<int> &perm = *perm_ptr;
  // 2, 0, 1, 3 apply this to A.
  // How to do this ?
  // The array A should look like
  /**
   * A[2], A[0], A[1], A[3]
   * We can copy the elements to permutation
   * vector and return that instead of A. Can't we ?
   * Ofcourse. But how ?
   *
   * But is there a clever way to do this, so that
   * we apply this directly to A itself.
   *
   * In order not to overwrite this A[0] we need to
   * find in which position we can write A[0]
   *
   * But how to do that ? we can go to A[0]
   *
   * Keep going to the parents until the position equals the
   * index or until we find the index that we started at,
   *
   * */
  for(int i=0; i<perm.size(); i++){
    // [2, 0, 1, 3]
    // j = 2
    // j = 1
    // j = 0
    // j = 2
    /*
     * 0, 2, 0, 1, 3
     * A[0], A[2]
     * 
     * */
    while( perm[i] != i){
      swap(A[i], A[perm[i]]);
      swap(perm[i], perm[perm[i]]);
    }
  }
  return;
}
vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
