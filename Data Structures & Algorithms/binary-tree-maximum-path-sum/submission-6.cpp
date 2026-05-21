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
    void dfs(TreeNode* root, int& max_sum, int sum) {
        if (!root) return;
        sum += root->val;
        max_sum = max(max_sum, sum);

        dfs(root->left, max_sum, sum);
        dfs(root->right, max_sum, sum);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return INT_MIN;
        int max_left = 0;
        int max_right = 0;

        dfs(root->left, max_left, 0);
        dfs(root->right, max_right, 0);

        int ans = root->val + max_left + max_right;

        ans = max(ans, maxPathSum(root->left));
        ans = max(ans, maxPathSum(root->right));

        return ans;
    }
};
