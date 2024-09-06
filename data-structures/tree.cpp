#include <iostream>

class TreeNode {
  public:
    TreeNode *left;
    TreeNode *right;
    int data;

    TreeNode(int data) : left(NULL), right(NULL), data(data) {} 
};

class TreeBinary {
  public:
    TreeNode *root;

    TreeBinary() {
      TreeNode *first = new TreeNode(1);
      TreeNode *second = new TreeNode(2);
      TreeNode *third = new TreeNode(3);
      TreeNode *fourth = new TreeNode(4);

      root = first;

      first->left = second;
      first->right = third;
      second->left = fourth; 
  }

  void preOrder(TreeNode *node) {
    if (node == NULL) return;

    std::cout << node->data << " -> ";
    preOrder(node->left);
    preOrder(node->right);
  }
};

int main() {
  TreeBinary tree;
  tree.preOrder(tree.root);
  
  return 0;
}