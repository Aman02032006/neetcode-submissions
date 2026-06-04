class Solution {
    const int INF = 100;
    int n, m;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));

        queue<pair<int, int>> q;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
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

                if (valid(r, c) && dist[r][c] == INF && grid[r][c] == 1) {
                    dist[r][c] = 1 + dist[i][j];
                    q.push({r, c});
                }
            }
        }

        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (dist[i][j] == INF) {
                    if (grid[i][j] == 1) return -1;
                }
                else ans = max(ans, dist[i][j]);
            }
        }

        return ans;
    }
};
