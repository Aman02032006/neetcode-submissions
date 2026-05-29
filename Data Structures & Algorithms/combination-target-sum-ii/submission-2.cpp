class Solution {
    vector<int> tmp;
    vector<vector<int>> res;
    unordered_map<int, int> freq;

    void backtrack(int idx, int curr, int target, vector<int>& nums) {
        if (curr == target) {
            res.push_back(tmp);
            return;
        }

        if (curr > target) return;

        for (int i = idx ; i < nums.size() ; i++) {
            if (!freq[nums[i]]) continue;
            tmp.push_back(nums[i]);
            freq[nums[i]]--;
            backtrack(i, curr + nums[i], target, nums);
            tmp.pop_back();
            freq[nums[i]]++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        tmp.clear();
        sort(nums.begin(), nums.end());

        vector<int> A;
        for (int num : nums) {
            if (freq.find(num) == freq.end()) A.push_back(num);
            freq[num]++;
        }

        backtrack(0, 0, target, A);
        return res;
    }
};
