class Solution {
    vector<string> path;
    unordered_map<string, vector<string>> adj;

    void dfs(string s) {
        while (!adj[s].empty()) {
            string u = adj[s].back();
            adj[s].pop_back();
            dfs(u);
        }

        path.push_back(s);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];

            adj[from].push_back(to);
        }

        for (auto &p : adj) {
            sort(p.second.rbegin(), p.second.rend());
        }

        dfs("JFK");

        reverse(path.begin(), path.end());

        return path;
    }
};