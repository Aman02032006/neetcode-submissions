class Solution {
    vector<pair<int, int>> positions;
    vector<vector<string>> res;

    bool valid(pair<int, int> pos) {
        for (auto p : positions) {
            if (p.first == pos.first) return false;
            if (p.second == pos.second) return false;
            if (p.first + p.second == pos.first + pos.second) return false;
            if (p.first - p.second == pos.first - pos.second) return false;
        }

        return true;
    } 

    void backtrack(int k, int n) {
        if (k == n) {
            vector<string> tmp;
            for (int i = 0 ; i < n ; i++) {
                string t = "";
                for (int j = 0 ; j < n ; j++) t += '.';
                tmp.push_back(t);
            }

            for (auto p : positions) {
                tmp[p.first - 1][p.second - 1] = 'Q';
            }

            res.push_back(tmp);
            return;
        }

        for (int i = (positions.size()) ? positions.back().first + 1 : 1; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (valid({i, j})) {
                    positions.emplace_back(i, j);
                    backtrack(k + 1, n);
                    positions.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        backtrack(0, n);

        return res;
    }
};
