class Solution {
    bool dfs(int u, int p, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for (int w : adj[u]) {
            if (w == p) continue;
            if (visited[w]) return false;
            if (!dfs(w, u, adj, visited)) return false; 
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        bool valid = dfs(0, -1, adj, visited);

        for (bool visit : visited) {
            if (!visit) valid = false;
        }

        return valid;
    }
};
