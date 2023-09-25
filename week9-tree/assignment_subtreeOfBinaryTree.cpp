// Time complexity: O(n), where, n is each Node in the Binary Search Tree.
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
void getSubtree(TreeNode *, int, bool *);

int main() {
    int value = 4, size = 5;
    std::cin >> value >> size;

    bool foundSubtree = false;
    bool *ptrFoundSubtree = &foundSubtree;

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

    // readBinaryTree(root);
    // std::cout << std::endl;

    getSubtree(root, value, ptrFoundSubtree);
    if (*ptrFoundSubtree == false) {
        std::cout << "¯\\_(ツ)_/¯"; // Shrug emoji, with '\' Escape character
    }
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

void getSubtree(TreeNode *root, int value, bool *foundSubtree) {
    if (root == nullptr) {
        return;
    }

    if (root->val == value) {
        readBinaryTree(root);
        *foundSubtree = true;
        return;
    }

    // Searching deeper into the tree for a match:
    getSubtree(root->left, value, foundSubtree);
    getSubtree(root->right, value, foundSubtree);

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