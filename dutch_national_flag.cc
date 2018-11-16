#include <array>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
typedef enum { kRed, kWhite, kBlue } Color;

using namespace std;

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
  /*
   *  Given the pivot index, parition the array such that all the elements
   *  less than the pivot appear before all the elements equal to the pivot
   *  followed by all the elements greater than the pivot.
   *
   *  Maintain two indices, one for the boundary between less and equal and
   *  one for the boundary between equal and more.
   *
   *  A <0, 1, 2, 0, 2, 1, 1>
   *  B <0, 1, 0, 1, 1, 2, 2>
   *
   * */

  vector<Color>& A = *A_ptr;
  Color pivot = A[pivot_index];
  int n = A.size();
  int i=0, j=n-1, k=0;

  // In the first pass just move all the elements less than pivot to the front,

  while(k < n){
    if(A[k] < pivot){
      swap(A[k++], A[i++]);
    }
    else{
      k++;
    }
  }
  k = n-1;
  while(k >= 0){
    if(A[k] > pivot){
      swap(A[k--], A[j--]);
    }
    else
      k--;
  }
  return;
}
void DutchFlagPartitionWrapper(TimedExecutor& executor, const vector<int>& A,
                               int pivot_idx) {
  vector<Color> colors;
  colors.resize(A.size());
  std::array<int, 3> count = {0, 0, 0};
  for (size_t i = 0; i < A.size(); i++) {
    count[A[i]]++;
    colors[i] = static_cast<Color>(A[i]);
  }
  Color pivot = colors[pivot_idx];

  executor.Run([&] { DutchFlagPartition(pivot_idx, &colors); });

  int i = 0;
  while (i < colors.size() && colors[i] < pivot) {
    count[colors[i]]--;
    ++i;
  }

  while (i < colors.size() && colors[i] == pivot) {
    count[colors[i]]--;
    ++i;
  }

  while (i < colors.size() && colors[i] > pivot) {
    count[colors[i]]--;
    ++i;
  }

  if (i != colors.size()) {
    throw TestFailure("Not partitioned after " + std::to_string(i) +
                      "th element");
  } else if (count != std::array<int, 3>{0, 0, 0}) {
    throw TestFailure("Some elements are missing from original array");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A", "pivot_idx"};
  return GenericTestMain(args, "dutch_national_flag.cc",
                         "dutch_national_flag.tsv", &DutchFlagPartitionWrapper,
                         DefaultComparator{}, param_names);
}
