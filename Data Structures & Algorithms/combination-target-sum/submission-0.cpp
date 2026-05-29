class Solution {
    vector<int> tmp;
    vector<vector<int>> res;

    void backtrack(int idx, int curr, int target, vector<int>& nums) {
        if (curr == target) {
            res.push_back(tmp);
            return;
        }

        if (curr > target) return;

        for (int i = idx ; i < nums.size() ; i++) {
            tmp.push_back(nums[i]);
            backtrack(i, curr + nums[i], target, nums);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        tmp.clear();
        backtrack(0, 0, target, nums);

        return res;
    }
};
