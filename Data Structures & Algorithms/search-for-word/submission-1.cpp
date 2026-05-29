class Solution {
    bool found = false;
    void backtrack(int r, int c, int idx, vector<vector<char>>& board, string word) {
        if (idx == word.size()) {
            found = true;
            return;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#' || board[r][c] != word[idx]) return;

        char ch = board[r][c];
        board[r][c] = '#';

        backtrack(r - 1, c, idx + 1, board, word);
        if (found) return;
        backtrack(r, c + 1, idx + 1, board, word);
        if (found) return;
        backtrack(r + 1, c, idx + 1, board, word);
        if (found) return;
        backtrack(r, c - 1, idx + 1, board, word);

        board[r][c] = ch;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                backtrack(i, j, 0, board, word);
                if (found) return true;
            }
        }

        return false;
    }
};
