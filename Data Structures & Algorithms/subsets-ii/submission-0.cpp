class Solution {
    vector<int> tmp;
    vector<vector<int>> res;
    unordered_map<int, int> freq;

    void backtrack(int idx, vector<int>& a) {
        res.push_back(tmp);

        for (int i = idx ; i < a.size() ; i++) {
            if (!freq[a[i]]) continue;
            tmp.push_back(a[i]);
            freq[a[i]]--;
            backtrack(i, a);
            tmp.pop_back();
            freq[a[i]]++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        for (int num : nums) {
            if (freq.find(num) == freq.end()) a.push_back(num);
            freq[num]++;
        }

        tmp.clear();
        backtrack(0, a);

        return res;
    }
};
