class Node {
public:
    unordered_map<char, Node*> children;
    string word = "";
};

class PrefixTree {
public:
    Node* root = new Node();
    PrefixTree() {}
    
    void insert(string word) {
        auto tmp = root;
        for (char ch : word) {
            if (tmp->children.find(ch) == tmp->children.end()) {
                Node* tmp2 = new Node();
                tmp->children[ch] = tmp2;
            }
            tmp = tmp->children[ch];
        }
        tmp->word = word;
    }
};

class Solution {
    vector<string> res;

    void DFS(int r, int c, Node* node, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#') return;

        char ch = board[r][c];
        if (node->children.find(ch) == node->children.end()) return;

        node = node->children[ch];

        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';

        DFS(r - 1, c, node, board);
        DFS(r, c + 1, node, board);
        DFS(r + 1, c, node, board);
        DFS(r, c - 1, node, board);

        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree* trie = new PrefixTree();
        for (string word : words) trie->insert(word);

        res.clear();

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                DFS(i, j, trie->root, board);
            }
        }

        return res;
    }
};
