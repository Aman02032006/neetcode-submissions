class Solution {
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& state) {
        state[u] = 1;
        for (int w : adj[u]) {
            if (state[w] == 1) return true;
            if (state[w] == 0) {
                if (dfs(w, adj, state)) return true;
            }
        }

        state[u] = 2;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto preq : prerequisites) adj[preq[1]].push_back(preq[0]);

        vector<int> state(n, 0);

        for (int i = 0 ; i < n ; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) return false;
            }
        }

        return true;
    }
};
