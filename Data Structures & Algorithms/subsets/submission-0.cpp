class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        int n = nums.size();
        for (int m = 0 ; m < (1 << n) ; m++) {
            vector<int> tmp;
            for (int i = 0 ; i < n ; i++) {
                if ((m >> i) & 1) tmp.push_back(nums[i]);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
