#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using namespace std;

/* Testing if a tree is height balanced.
 *
 *
 *
 * */
int height(BinaryTreeNode<int>* tree){

  if(!tree)
    return 0;

  int hl = height(tree->left.get());
  int hr = height(tree->right.get());
  if(hl == -1 || hr == -1)
    return -1;

  if(abs(hl-hr)>1)
    return -1;
  else
    return 1+max(hl, hr);

  //return tree ? 1 + max(height(tree->left.get()), height(tree->right.get())) : 0;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return height(tree.get())!=-1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
