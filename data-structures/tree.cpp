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
};

int main() {
  TreeBinary tree;
  tree.preOrder(tree.root);
  std::cout << std::endl;
  tree.iterativePreOrder();
  std::cout << std::endl;
  tree.levelOrder(tree.root);

  return 0;
}