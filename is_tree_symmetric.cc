#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using namespace std;

bool CheckSymmetric(BinaryTreeNode<int>* ltree, BinaryTreeNode<int>* rtree) {
  /*
   * Are these two trees mirror images of each other.
   * */
  if(!ltree ^ !rtree)
    return false;
  if(!ltree && !rtree)
    return true;

  if(ltree->data != rtree->data)
    return false;

  return CheckSymmetric(ltree->left.get(), rtree->right.get()) &&
          CheckSymmetric(ltree->right.get(), rtree->left.get());
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  /* In order to check if this tree is symmetric, we just
   * need to it's subtrees are symmetric aka mirror images.
   * Let's assume that the given tree is a complete binary
   * tree, then in order for this tree to be symmetric,
   * it's left subtree is the mirror image of the right
   *
   * */


  if(!tree)
     return true;

  return CheckSymmetric(tree->left.get(), tree->right.get());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
