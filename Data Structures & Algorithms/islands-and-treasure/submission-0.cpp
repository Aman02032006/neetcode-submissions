class Solution {
    const int INF = 2147483647;
    int n, m;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            for (auto dir : dirs) {
                int r = i + dir.first;
                int c = j + dir.second;

                if (valid(r, c) && grid[r][c] == INF) {
                    grid[r][c] = 1 + grid[i][j];
                    q.push({r, c});
                }
            }
        }
    }
};
