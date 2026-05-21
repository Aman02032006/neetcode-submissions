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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s;

        s += to_string(root->val);
        s += '(' + serialize(root->left) + ")(" + serialize(root->right) + ')';

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        int i = 0;
        while (data[i] != '(') i++;
        int root_value = stoi(data.substr(0, i));
        TreeNode* root = new TreeNode(root_value);

        int open = 1;
        int j;
        for (j = i + 1 ; j < data.size() ; j++) {
            if (data[j] == '(') open++;
            if (data[j] == ')') open--;

            if (open == 0) break; 
        }

        root->left = deserialize(data.substr(i + 1, j - i - 1));

        i = j + 1;
        open = 1;
        for (j = i + 1 ; j < data.size() ; j++) {
            if (data[j] == '(') open++;
            if (data[j] == ')') open--;

            if (open == 0) break; 
        }

        root->right = deserialize(data.substr(i + 1, j - i - 1));

        return root;
    }
};
