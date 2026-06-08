class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxProd(n, INT_MIN);
        vector<int> minProd(n, INT_MAX);

        maxProd[0] = minProd[0] = nums[0];

        for (int i = 1 ; i < n ; i++) {
            if (nums[i] >= 0) {
                maxProd[i] = max(nums[i], maxProd[i - 1] * nums[i]);
                minProd[i] = min(nums[i], minProd[i - 1] * nums[i]);
            }
            else {
                maxProd[i] = max(nums[i], minProd[i - 1] * nums[i]);
                minProd[i] = min(nums[i], maxProd[i - 1] * nums[i]);
            }
        }

        return *max_element(maxProd.begin(), maxProd.end());
    }
};
