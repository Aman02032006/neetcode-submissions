/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root, int max_val = -101) {
        if (!root) return 0;

        if (root->val >= max_val) return 1 + goodNodes(root->left, max(root->val, max_val)) + goodNodes(root->right, max(max_val, root->val));
        else return goodNodes(root->left, max_val) + goodNodes(root->right, max_val);
    }
};
