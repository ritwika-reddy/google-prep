#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using namespace std;

/*
 *
 * */

int SumOfLeaves(BinaryTreeNode<int>* tree, int current){

  if(!tree)
    return 0;

  int updated = tree->data + 2*current;

  BinaryTreeNode<int>* left = tree->left.get();
  BinaryTreeNode<int>* right = tree->right.get();

  if(!left && !right)
    return updated;

  int leftSum = SumOfLeaves(tree->left.get(), updated);
  int rightSum = SumOfLeaves(tree->right.get(), updated);

  return leftSum + rightSum;
}

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {

  return SumOfLeaves(tree.get(), 0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "sum_root_to_leaf.cc", "sum_root_to_leaf.tsv",
                         &SumRootToLeaf, DefaultComparator{}, param_names);
}
