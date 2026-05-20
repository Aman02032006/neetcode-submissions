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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> list;
        if (!root) return list;

        vector<int> tmp = {root->val};
        list.push_back(tmp);

        auto l1 = levelOrder(root->left);
        auto l2 = levelOrder(root->right);

        int k = min(l1.size(), l2.size());

        for (int i = 0 ; i < min(l1.size(), l2.size()) ; i++) {
            tmp.clear();
            for (int w : l1[i]) tmp.push_back(w);
            for (int w : l2[i]) tmp.push_back(w);
            list.push_back(tmp);            
        }

        if (l1.size() > l2.size()) {
            for (int i = k ; i < l1.size() ; i++) list.push_back(l1[i]);
        }
        else {
            for (int i = k ; i < l2.size() ; i++) list.push_back(l2[i]);
        }

        return list;
    }
};
