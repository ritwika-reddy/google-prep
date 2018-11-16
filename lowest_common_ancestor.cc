#include <memory>
#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;

using namespace std;

struct Status{
    int num_target_nodes;
    BinaryTreeNode<int>* ancestor;
};

/*
 * This function returns the ancestor of the node if found, otherwise null from
 * that subtree.
 * */
Status findAncestor(BinaryTreeNode<int>* node0, BinaryTreeNode<int>* node1,
                          BinaryTreeNode<int>* tree){

  if(!tree)
    return {0, nullptr};

  if(tree == node0 || tree == node1)
    return {1, tree};

  Status leftS = findAncestor(node0, node1, tree->left.get());
  Status rightS = findAncestor(node0, node1, tree->right.get());

  if(leftS.num_target_nodes == 1 && rightS.num_target_nodes==1)
    return {2, tree};

  if(leftS.num_target_nodes == 2)
    return leftS;
  if(rightS.num_target_nodes == 2)
    return rightS;

}

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {

  BinaryTreeNode<int>* leftA = findAncestor(node0.get(), node1.get(), tree->left.get());
  BinaryTreeNode<int>* rightA = findAncestor(node0.get(), node1.get(), tree->right.get());

  if(leftA != rightA)
    return tree.get();

  return nullptr;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return LCA(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
