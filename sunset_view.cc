#include <iterator>
#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

/*
 * Buildings are given in the east to west order.
 * Now find all the buildings that can view the sunset.
 *
 * A building cannot view the sunset if there's another
 * building after this current one with greater height.
 *
 * Right ?
 * */

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {

    struct Building{
        int id;
        int height;
    };
    vector<int> ans;
    stack<Building> currentView;
    int i=0;
    while(sequence_begin != sequence_end) {
      int height = *sequence_begin++;
      Building building;
      building.height = height;
      building.id = i++;
      while(!currentView.empty() && currentView.top().height <= height)
        currentView.pop();

      currentView.push(building);
    }

  for(; !currentView.empty(); currentView.pop())
    ans.push_back(currentView.top().id);

  return ans;
}
vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "sunset_view.cc", "sunset_view.tsv",
                         &ExamineBuildingsWithSunsetWrapper,
                         DefaultComparator{}, param_names);
}
