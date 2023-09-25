// Time complexity: O(n)
// Space complexity: O(n)

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
void readBinaryTree(TreeNode *);
int getTreeHeight(TreeNode *);

int main() {
    int size = 5;
    std::cin >> size;

    TreeNode *root = nullptr; // Initialize an empty tree

    // root = insert(root, 10);
    // root = insert(root, 11);
    // root = insert(root, 1);
    // root = insert(root, 5);
    // root = insert(root, 3);
    // root = insert(root, 2);
    // root = insert(root, 7);
    for (int i = 0; i < size; i++) {
        int x;
        std::cin >> x;
        root = insert(root, x);
    }

    readBinaryTree(root);
    std::cout << std::endl;

    int height = getTreeHeight(root);
    std::cout << height << std::endl;

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

// Pre-order Traversal:
void readBinaryTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    readBinaryTree(root->left);
    std::cout << root->val << ' ';
    readBinaryTree(root->right);

    return;
}

int getTreeHeight(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getTreeHeight(root->left) + 1;
    int rightHeight = getTreeHeight(root->right) + 1;

    return std::max(leftHeight, rightHeight);
}

/*

Question

Write a function that does the following task.

    Given the root of a binary tree, return its Height. A binary tree's Height
is the number of nodes along the longest path from the root node down to the
    farthest leaf node.

    Mention the time and space complexity of your solution.

    Constraints:
        The number of nodes in the tree is in the range [0, 10^4].
        -100 <= Node.val <= 100

    Input Explanation: You will be given a tree as input. The example inputs are
    shown as an array for simplification only.

    In the array, the (2^index) is the left child and (2^index + 1) is the right
    child of the node at 'index'. In this case, index=0 is the root of the tree.

    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: 3

        Explanation: the tree is visually as following
        3

        /  \

        9   20

            /  \

            7  15

    Example 2:
        Input: root = [1,null,2]
        Output: 2

        Explanation: the tree is visually as following
        1

        /  \

            2

*/