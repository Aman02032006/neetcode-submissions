class Solution {
    int n, m;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool valid (int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> adj(n * m);
        vector<int> deg(n * m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto [x, y] : dirs) {
                    int r = i + x;
                    int c = j + y;

                    if (valid(r, c) && matrix[r][c] > matrix[i][j]) {
                        adj[i * m + j].push_back(r * m + c);
                        deg[r * m + c]++;
                    }
                }
            }
        }

        queue<int> q;
        int res = 0;

        for (int i = 0; i < n * m; i++) {
            if (deg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int l = q.size();
            res++;
            while (l--) {
                int u = q.front();
                q.pop();

                for (int w : adj[u]) {
                    deg[w]--;
                    if (deg[w] == 0) q.push(w);
                }
            }
        }

        return res;
    }
};
