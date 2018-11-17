#include <memory>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

using namespace std;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  /*
   *
   * */

  if(!tree)
    return false;

  remaining_weight -= tree->data;

  if(!tree->left && !tree->right){
    if(remaining_weight == 0)
      return true;
    else
      return false;
  }

  return HasPathSum(tree->left, remaining_weight) ||
          HasPathSum(tree->right, remaining_weight);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.cc", "path_sum.tsv", &HasPathSum,
                         DefaultComparator{}, param_names);
}
