class Solution {
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for (int w : adj[u]) {
            if (visited[w]) continue;
            dfs(w, adj, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int comp = 0;
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                comp++;
                dfs(i, adj, visited);
            }
        }

        return comp;
    }
};
