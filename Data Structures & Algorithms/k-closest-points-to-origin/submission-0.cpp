class Solution {
    static bool cmp(vector<int>& a, vector<int> &b) {
        return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);

        vector<vector<int>> res;
        for (int i = 0 ; i < k ; i++) res.push_back(points[i]);

        return res;
    }
};
