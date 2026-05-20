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
    int min_element(TreeNode* root) {
        if (!root) return 1001;

        auto tmp = root;
        while (tmp -> left) tmp = tmp->left;

        return tmp->val;
    }

    int max_element(TreeNode* root) {
        if (!root) return -1001;

        auto tmp = root;
        while (tmp -> right) tmp = tmp->right;

        return tmp->val;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        int left_max = max_element(root->left);
        int right_min = min_element(root->right);

        if (left_max >= root->val || right_min <= root->val) return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};
