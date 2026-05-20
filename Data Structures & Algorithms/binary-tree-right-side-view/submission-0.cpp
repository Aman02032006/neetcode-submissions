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

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            while(len--) {
                TreeNode* u = q.front();
                q.pop();
                tmp.push_back(u->val);
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }

            list.push_back(tmp);
        }

        return list;
    }
    vector<int> rightSideView(TreeNode* root) {
        auto levelOrderList = levelOrder(root);
        vector<int> rightSideViewList(levelOrderList.size());
        
        int height = rightSideViewList.size();
        for (int i = 0 ; i < height ; i++) rightSideViewList[i] = levelOrderList[i].back();

        return rightSideViewList;
    }
};
