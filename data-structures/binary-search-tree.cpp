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

    TreeNode* search(TreeNode *node, int value) {
      if (node == nullptr || value == node->data) {
        return node;
      }

      if (value < node->data) {
        return search(node->left, value);
      } else {
        return search(node->right, value);
      }
    }

    bool isValid(TreeNode *node, int min, int max) {
      if (node == nullptr) return true;

      if (node->data <= min || node->data >= max) return false;

      bool left = isValid(node->left, min, node->data);

      if (left) {
        return isValid(node->right, node->data, max);
      }

      return false;
    }
};

int main() {
  BinarySearchTree *tree = new BinarySearchTree();
  tree->root = tree->insert(tree->root, 5);
  tree->root = tree->insert(tree->root, 2);
  tree->root = tree->insert(tree->root, 7);

  bool isValid = tree->isValid(tree->root, -2147483648, 2147483647);
  std::cout << "Is valid: " << isValid << std::endl;

  TreeNode *node = tree->search(tree->root, 5);
  node == nullptr 
    ? std::cout << "Null"
    : std::cout << node->data;
  
  std::cout << '\n';
  return 0;
}