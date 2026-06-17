class Solution {
    int dist(vector<int> v1, vector<int> v2) {
        return abs(v1[1] - v2[1]) + abs(v1[0] - v2[0]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = n - 1;
        vector<pair<int, int>> MST;
        int mstCost = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        vector<bool> visited(n, false);
        
        for (int i = 1; i < n; i++) {
            q.push({dist(points[0], points[i]), 0, i});
        }
        visited[0] = true;

        while (!q.empty() && MST.size() < m) {
            auto [d, i, j] = q.top();
            q.pop();

            if (visited[j]) continue;
            visited[j] = true;

            MST.push_back({i, j});
            mstCost += d;

            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                if (visited[k]) continue;

                q.push({dist(points[j], points[k]), j, k});
            }
        }

        for (auto p : MST) {
            cout << p.first << " " << p.second << endl;
        }

        return mstCost;
    }
};
