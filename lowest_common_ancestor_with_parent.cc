#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using namespace std;

int height(BinaryTreeNode<int>* node){
  int h = 0;
  while(node != nullptr){
    node = node->parent;
    ++h;
  }
  return h;
}
BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  /*
   * Find the nodes in the trre and find the search paths.
   *
   * Move the search paths up so that both of them are of the same
   * length and then find the lowest common ancestor by moving them
   * both in tandem.
   *
   * The tree is not given because we already have the
   * */

  int h0 = height(node0.get());
  int h1 = height(node1.get());

  BinaryTreeNode<int> *node = (h0 > h1) ? node0.get() : node1.get();
  BinaryTreeNode<int> *other = (h1 < h0 ) ? node1.get(): node0.get();

  if(h0 < h1)
    swap(h0, h1);

  while(h0-- != h1){
    node = node->parent;
  }

  while(other != node){
    other = other->parent;
    node = node->parent;
  }

  return node;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return LCA(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
