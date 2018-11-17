#include <istream>
#include <memory>
#include <string>
#include <vector>
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
using std::unique_ptr;

using namespace std;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  int size;
};

const BinaryTreeNode<int>* FindKthNodeBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree, int k) {
  /*
   * TreeNode stores the size of the subtree rooted
   * at that node.
   * So we can use this information to computet the kth
   * node efficiently. Sort of like Binary search where we
   * eliminate a part of the array.
   *
   * Here we can eliminate the left or the right subtree.
   *
   * Also because it's the inorder traversal, the left
   * subtree is processed before the right subtree
   * and so we are only concerned with the size of the
   * left subtree since they come before the current node.
   * */
  int before = 0, after = 0;

  if(tree->left)
    before = tree->left->size;

  if(tree->right)
    after = tree->right->size;

  if(k <= before)
    return FindKthNodeBinaryTree(tree->left, k);
  else{
    if(k - before == 1)
      return tree.get();
    else
      return FindKthNodeBinaryTree(tree->right, k - before - 1);
  }


//  return nullptr;
}
template <typename KeyT>
struct SerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>>
    : BinaryTreeSerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>,
                                    false> {
  using serialization_type = std::unique_ptr<BinaryTreeNode<KeyT>>;
  using base =
      BinaryTreeSerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>,
                                    false>;
  static serialization_type Parse(const std::string& str) {
    auto tree = base::Parse(str);
    InitSize(tree);
    return std::move(tree);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    auto tree = base::JsonParse(json_object);
    InitSize(tree);
    return std::move(tree);
  }

 private:
  static int InitSize(const serialization_type& node) {
    if (!node) return 0;
    node->size = 1 + InitSize(node->left) + InitSize(node->right);
    return node->size;
  }
};

namespace detail {
template <typename KeyT>
struct IsBinaryTreeImpl<std::unique_ptr<BinaryTreeNode<KeyT>>>
    : std::true_type {};
}  // namespace detail

int FindKthNodeBinaryTreeWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                                 int k) {
  auto result = FindKthNodeBinaryTree(tree, k);
  if (!result) {
    throw TestFailure("Result can't be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  return GenericTestMain(args, "kth_node_in_tree.cc", "kth_node_in_tree.tsv",
                         &FindKthNodeBinaryTreeWrapper, DefaultComparator{},
                         param_names);
}
