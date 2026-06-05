class Solution {
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
        state[u] = 1;
        for (int w : adj[u]) {
            if (state[w] == 1) return true;
            if (state[w] == 0) {
                if (dfs(w, adj, state, order)) return true;
            }
        }

        state[u] = 2;
        order.push_back(u);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto preq : prerequisites) adj[preq[0]].push_back(preq[1]);

        vector<int> state(n, 0);
        vector<int> order;

        for (int i = 0 ; i < n ; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state, order)) return {};
            }
        }

        return order;
    }
};
