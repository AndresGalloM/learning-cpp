#include <iostream>

class TreeNode {
  public:
    TreeNode *left;
    TreeNode *right;
    int data;

    TreeNode(int data) : left(nullptr), right(nullptr), data(data) {} 
};

class BinarySearchTree {
  public:
    TreeNode *root = nullptr;

    TreeNode* insert(TreeNode *node, int value) {
      if(node == nullptr) {
        node = new TreeNode(value);
        return node; 
      }

      if(value < node->data) {
        node->left = insert(node->left, value);
      } else {
        node->right = insert(node->right, value);
      }

      return node;
    }
};

int main() {
  BinarySearchTree *tree = new BinarySearchTree();
  tree->root = tree->insert(tree->root, 5);
  tree->root = tree->insert(tree->root, 2);
  tree->root = tree->insert(tree->root, 7);
  std::cout << tree->root->data << std::endl;
  std::cout << tree->root->left->data << std::endl;
  std::cout << tree->root->right->data << std::endl;

  
  return 0;
}