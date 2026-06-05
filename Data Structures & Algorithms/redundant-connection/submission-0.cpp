class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> removed(n + 1, false);
        vector<int> degree(n + 1, 0);
        queue<int> q;

        for (int i = 1 ; i <= n ; i++) {
            degree[i] = adj[i].size();
            if (degree[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            removed[u] = true;

            for (int w : adj[u]) {
                if (removed[w]) continue;
                degree[w]--;
                if (degree[w] == 1) q.push(w);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (!removed[edges[i][0]] && !removed[edges[i][1]]) return edges[i];
        }

        return {};
    }
};
