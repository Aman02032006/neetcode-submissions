class Solution {
    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
