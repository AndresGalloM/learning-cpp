#include <iostream>
#include <stack>
#include <queue>

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
      TreeNode *first = new TreeNode(6);
      TreeNode *second = new TreeNode(2);
      TreeNode *third = new TreeNode(7);
      TreeNode *fourth = new TreeNode(2);

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

  void iterativePreOrder() {
    if (root == NULL) return;

    std::stack<TreeNode *> stack;
    stack.push(root);

    while(!stack.empty()) {
      TreeNode *temp = stack.top();
      stack.pop();

      std::cout << temp->data << " -> ";

      if (temp->right != NULL) {
        stack.push(temp->right);
      }

      if (temp->left != NULL) {
        stack.push(temp->left);
      }
    }
  }

  void levelOrder(TreeNode *node) {
    if (node == NULL) return;

    std::queue<TreeNode *> queue;
    queue.push(node);

    while(!queue.empty()) {
      TreeNode *temp = queue.front();
      queue.pop();
      std::cout << temp->data << " -> ";
    
      if (temp->left != NULL) {
        queue.push(temp->left);
      }

      if (temp->right != NULL) {
        queue.push(temp->right);
      }
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
  TreeBinary tree;
  bool valid = tree.isValid(tree.root, -2147483648, 2147483647);

  std::cout << "Is valid: " << valid << std::endl;

  tree.preOrder(tree.root);
  std::cout << std::endl;
  tree.iterativePreOrder();
  std::cout << std::endl;
  tree.levelOrder(tree.root);

  return 0;
}