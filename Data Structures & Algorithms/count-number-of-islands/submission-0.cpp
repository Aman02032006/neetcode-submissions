class Solution {
    int n, m;
    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();
            if (valid(r - 1, c) && grid[r - 1][c] == '1' && !visited[r - 1][c]) {
                q.push({r - 1, c});
                visited[r - 1][c] = true;
            }
            if (valid(r, c + 1) && grid[r][c + 1] == '1' && !visited[r][c + 1]) {
                q.push({r, c + 1});
                visited[r][c + 1] = true;
            }
            if (valid(r + 1, c) && grid[r + 1][c] == '1' && !visited[r + 1][c]) {
                q.push({r + 1, c});
                visited[r + 1][c] = true;
            }
            if (valid(r, c - 1) && grid[r][c - 1] == '1' && !visited[r][c - 1]) {
                q.push({r, c - 1});
                visited[r][c - 1] = true;
            }
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int comps = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    comps++;
                    bfs(i, j, grid, visited);
                }
            }
        }

        return comps;
    }
};
