class Solution {
    int n, m;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(queue<pair<int, int>> q, vector<vector<int>>& heights, vector<vector<int>>& reach, vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            reach[i][j]++;
            for (auto dir : dirs) {
                int r = i + dir.first;
                int c = j + dir.second;

                if (valid(r, c) && !visited[r][c] && heights[r][c] >= heights[i][j]) {
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> reach(n, vector<int>(m, 0));
        queue<pair<int, int>> q1, q2;
        vector<vector<bool>> v1(n, vector<bool>(m, false)), v2(n, vector<bool>(m, false));

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (i == 0 || j == 0) {
                    q1.push({i, j});
                    v1[i][j] = true;
                }
                if (i == n - 1 || j == m - 1) {
                    q2.push({i, j});
                    v2[i][j] = true;
                }
            }
        }

        bfs(q1, heights, reach, v1);
        bfs(q2, heights, reach, v2);

        vector<vector<int>> res;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cout << reach[i][j] << " ";
                if (reach[i][j] == 2) res.push_back({i, j});
            }
            cout << endl;
        }

        return res;
    }
};
