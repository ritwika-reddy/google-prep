#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  /*
   *  At each position keep a track of the max position
   *  that can be reached starting at that index.
   *
   *  How to update ?
   *
   *  To find the max position that can be reached
   *  starting at the first index,
   *
   *  3, 3, 1, 0, 2, 0
   *  Now, how can we update the array ?
   *
   *  If an index j can be reached, does that mean all the indices
   *  i can be reached ? Yes. Why ? Because it's cumulative.
   *
   *  If you are at index j then it means that you either came here
   *  from j-1 or from some index before j-1 directly by taking that
   *  jump of k steps. This means that all the indices between
   *  that index and j are also reachable by taking the intermediate
   *  number of steps.
   *
   *  We just keep updating the maximum index that is reachable from
   *  the first index, If at any point that index is less
   *  than the current index then return false.
   * */
  int max_index = 0;
  for(int i=0; i<max_advance_steps.size(); i++){
    if(max_index < i)
      return false;
    max_index = max(max_index, i+max_advance_steps[i]);
  }
  if(max_index >= max_advance_steps.size()-1)
    return true;
  else
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
