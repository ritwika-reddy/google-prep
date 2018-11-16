#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

vector<int> NextPermutation(vector<int> perm) {
  /*
   *  Return the next permutation in dictionary ordering.
   *  What is the right most index such that there
   *  is an element to it's right which is greater than
   *  it.
   *
   *  Or starting from the right, what are the two
   *  consecutive elements such that the right element
   *  is less than the right element.
   * */
  vector<int> ans = perm;
  int n = perm.size();
  int left = -1;
  /*
  cout << endl;
  for(int i=0; i<n; i++)
    cout << ans[i] << " ";
  cout << endl;*/
  for(int i=n-1; i>=1; i--){
    if(perm[i-1] < perm[i]){
      left = i-1; // This is the first element smaller than the longest decreasing sequence
      // starting from the left.
      // Swap this with the smallest element to it's right.
      int minj = i-1;
      for(int j=n-1; j>=i;j--){
        if(perm[j] > perm[i-1]){
          minj = j;
          break;
        }
      }
      swap(ans[minj], ans[i-1]);
      reverse(ans.begin()+i, ans.end());
      break;
    }
  }
  if(left==-1)
    return {};
  /*
  cout << left << endl;
  for(int i=0; i<n; i++)
    cout << ans[i] << " ";
  cout << endl;*/
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
