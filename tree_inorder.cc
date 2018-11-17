#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

using namespace std;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {

  BinaryTreeNode<int>* current = tree.get();
  stack<BinaryTreeNode<int>*> st;

  vector<int> ans;
  st.push(current);
  if(!current)
    return ans;

  while(!st.empty()){
    BinaryTreeNode<int>* top = st.top();
    st.pop();
    //cout << top->data << endl;
    if(!top->left && !top->right) // Leaf or parent
      ans.push_back(top->data);
    else{ // If it's not a leaf or a parent, only then you'll push this value into the stack.
      // Otherwise you won't.
      // Because it's last in first out, right should be pushed first
      // since you want to process it last. Okay ?
      /*
       * Here if I change the order of pushing the left and right
       * subtrees would that simulate the call stack ?
       *
       * Let's say we first push the root and
       * then push the right subtree and left subtree,
       * in that case we are processing the root
       * before the left and right subtree.
       * So that's Preorder traversal.
       *
       * For post order, we'll first push the root,
       * right and then the left subtree. This would
       * give us the correct answer for postorder traversal.
       * */

      if(top->right)
        st.push(top->right.get());
      st.push(new BinaryTreeNode<int>(top->data));
      if(top->left)
        st.push(top->left.get());
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}
