class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto vec : times) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = -1;
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (d > dist[u]) continue;

            for (auto [v, t] : adj[u]) {
                if (d + t < dist[v]) {
                    dist[v] = d + t;
                    q.push({dist[v], v});
                }
            }
        }

        int res = *max_element(dist.begin(), dist.end());

        if (res == INT_MAX) return -1;
        else return res;
    }
};
