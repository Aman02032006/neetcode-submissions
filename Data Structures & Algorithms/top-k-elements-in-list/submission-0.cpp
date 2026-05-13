class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second >= b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;

        vector<pair<int, int>> elem;
        vector<int> kMostFrequent(k);
        for (auto p : freq) elem.push_back(p);

        sort(elem.begin(), elem.end(), cmp);

        for (int i = 0 ; i < k ; i++) kMostFrequent[i] = elem[i].first;

        return kMostFrequent;
    }
};
