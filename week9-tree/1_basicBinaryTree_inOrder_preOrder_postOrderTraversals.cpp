#include <iostream>

// Definition for a binary tree node.
class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *, int);
// TreeNode *readBinaryTree(TreeNode *);
void readBinaryTree(TreeNode *);

int main() {
    TreeNode *root = nullptr; // Initialize an empty tree

    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 7);

    readBinaryTree(root);
    std::cout << std::endl;

    return 0;
}

TreeNode *insert(TreeNode *root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        // Recursively insert into the left subtree:
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        // Recursively insert into the right subtree:
        root->right = insert(root->right, value);
    }

    return root; // Return the modified root
}

// In-order Traversal:
void readBinaryTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    readBinaryTree(root->left);
    std::cout << root->val << ' ';
    readBinaryTree(root->right);

    return;
}

// TODO // Pre-order Traversal:
// TODO // Post-order Traversal:

/*

  https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

  https://www.grepper.com/answers/583240/inorder+preorder+postorder?ucard=1
  Hint to Remember:
    - IN means root is in middle: inorder: left => root => right
    - PRE means root is at front: preorder: root => left => right
    - POST means root is at the end: postorder: left => right => root
  Always left comes first than right

  The above 3 are Depth-first Search. There's also Level Order Traversal
  (Breadth-first Search).


    10 11 1 5 3 2 7 =>
               10
            /       \
            1       11
           / \
             5
            / \
            3  7
           / \
           2
*/