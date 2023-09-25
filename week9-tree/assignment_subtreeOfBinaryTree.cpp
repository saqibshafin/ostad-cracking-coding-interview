// Time complexity:
// Space complexity:

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

void getSubtree(TreeNode *, int);

int main() {
    int value = 3, size;
    std::cin >> value >> size;

    TreeNode *root = nullptr; // Initialize an empty tree

    for (int i = 0; i < size; i++) {
        int x;
        std::cin >> x;
        root = insert(root, x);
    }

    // readBinaryTree(root);
    // std::cout << std::endl;

    getSubtree(root, value);
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

void getSubtree(TreeNode *root, int value) {
    if (root == nullptr) {
        return;
    }

    if (root->val == value) {
        readBinaryTree(root);
        return;
    }

    // Searching deeper into the tree for a match:
    getSubtree(root->left, value);
    getSubtree(root->right, value);

    return;
}

/*

Assignment on Tree

    Write a function that does the following task.

    You are given a binary search tree (BST) and an integer val. Find the node
in the BST that the node's value equals val and return the subtree rooted with
that node. If such a node does not exist, return null.

    Mention the time and space complexity of your solution.

    Constraints:

        The number of nodes in the tree is in the range [1, 5000].
        1 <= Node.val <= 10^7
        The tree is a binary search tree.
        1 <= val <= 10^7

    Note: You will be given the root node of the trees. The example inputs are
shown as an array for simplification only.

    Example 1:
        Input: tree = [4,2,7,1,3], val = 2
        Output: [2,1,3]

    Explanation:
        val = 2
        Input tree:
             4

            / \

            2  7

           / \

          1   3

        output:
        2

        / \

        1  3

        Or an array [2,1,3]

    Example 2:
        Input: tree= [4,2,7,1,3], val = 5
        Output: []

    Explanation:
        val: 5
        Input tree:

            4

            / \

        2  7

        / \

        1   3

        Output: null or an array []

*/