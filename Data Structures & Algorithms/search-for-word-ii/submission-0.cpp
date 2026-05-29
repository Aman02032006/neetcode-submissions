class Node {
public:
    unordered_map<char, Node*> children;
    bool isWord = false;
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
        tmp->isWord = true;
    }
};

class Solution {
    set<string> res;
    set<pair<int, int>> visit;

    void DFS(int r, int c, Node* node, string wordSoFar, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visit.find({r, c}) != visit.end() || node->children.find(board[r][c]) == node->children.end()) return;

        visit.insert({r, c});
        node = node->children[board[r][c]];
        wordSoFar += board[r][c];

        if (node->isWord) res.insert(wordSoFar);

        DFS(r - 1, c, node, wordSoFar, board);
        DFS(r, c + 1, node, wordSoFar, board);
        DFS(r + 1, c, node, wordSoFar, board);
        DFS(r, c - 1, node, wordSoFar, board);

        visit.erase({r, c});
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree* trie = new PrefixTree();
        for (string word : words) trie->insert(word);

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                DFS(i, j, trie->root, "", board);
            }
        }

        vector<string> result;
        for (auto word : res) result.push_back(word);

        return result;
    }
};
