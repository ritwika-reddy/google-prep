#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

using namespace std;

vector<vector<int>> BottomUpLtoR(const unique_ptr<BinaryTreeNode<int>>& tree){
  vector<vector<int>> levelOrder;

  return levelOrder;
}

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {

  vector<vector<int>> levelOrder;
  if(!tree)
    return levelOrder;
  int i=0;

  queue<BinaryTreeNode<int>*> parents;
  parents.push(tree.get());

  while(!parents.empty()){

    queue<BinaryTreeNode<int>*> children;
    levelOrder.push_back(vector<int>());

    while(!parents.empty()){

      auto parent = parents.front();
      levelOrder[i].push_back(parent->data);

      if(parent->left)
        children.push(parent->left.get());

      if(parents.front()->right)
        children.push(parent->right.get());
      parents.pop();
    }
    parents = children;
    i++;
  }

  return levelOrder;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
