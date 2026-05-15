class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lcs, freq;
        int max_lcs = 0;

        for (int i: nums) freq[i]++;
        for (int i: nums) {
            if (lcs[i] > 0) continue;

            int t = i;
            lcs[t++] = 1;
            while (freq[t]) {
                lcs[t] = lcs[t - 1] + 1;
                t++;
            }
        }

        for (auto p : lcs) max_lcs = max(max_lcs, p.second);

        return max_lcs;
    }
};
