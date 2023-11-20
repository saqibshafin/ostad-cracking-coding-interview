// Time Complexity: O(n^2)
// Space Complexity:

#include <vector>

using namespace std;

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

class Solution {
  public:
    int find_min(TreeNode *node) {
        int value = node->val;

        if (node->left) {
            int value_left = find_min(node->left);
            if (value_left < value) {
                value = value_left;
            }
        }

        if (node->right) {
            int value_right = find_min(node->right);
            if (value_right < value) {
                value = value_right;
            }
        }

        return value;
    };

    int find_max(TreeNode *node) {
        int value = node->val;

        if (node->left) {
            int value_left = find_max(node->left);
            if (value_left > value) {
                value = value_left;
            }
        }

        if (node->right) {
            int value_right = find_max(node->right);
            if (value_right > value) {
                value = value_right;
            }
        }

        return value;
    };

    bool is_valid_bst(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        if (root->left) {
            // comparing max_val with the root_val:
            int max_value = find_max(root->left);
            if (max_value >= root->val) {
                // if max_val is larger than or equal to the root_val (of a left
                // node) , it means, it's not a valid BST:
                return false;
            }
        }

        if (root->right) {
            // comparing min_val with the root_val:
            int min_value = find_min(root->right);
            if (min_value <= root->val) {
                // if min_val is smaller than or equal to root_val (of a right
                // node) , it means, it's not a valid BST:
                return false;
            }
        }

        // both the left and right subtrees must also be BSTs, that's why, we
        // are doing the following instead of just returning "true":
        return is_valid_bst(root->left) && is_valid_bst(root->right);
    }
};