class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> stops(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.push({0, 0, src});

        while (!q.empty()) {
            auto [d, stop, u] = q.top();
            q.pop();

            if (u == dst) return d;

            if (stop > k || stop >= stops[u]) continue;

            stops[u] = stop;

            for (auto [v, w] : adj[u]) {
                q.push({d + w, stop + 1, v});
            }
        }

        return -1;
    }
};
