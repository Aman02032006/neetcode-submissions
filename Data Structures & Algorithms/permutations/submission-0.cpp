class Solution {
    vector<int> tmp;
    vector<vector<int>> res;
    int n;

    void backtrack(int m, vector<int>& nums) {
        
        if (m == ((1 << n) - 1)) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0 ; i < n ; i++) {
            if ((m >> i) & 1) continue;
            tmp.push_back(nums[i]);
            backtrack(m + (1 << i), nums);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        backtrack(0, nums);

        return res;
    }
};
