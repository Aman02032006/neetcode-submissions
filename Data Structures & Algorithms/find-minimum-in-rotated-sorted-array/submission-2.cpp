class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.front() < nums.back()) return nums[0];

        int low = 0, high = nums.size() - 1, ans = nums.back();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }

        return ans;
    }
};
