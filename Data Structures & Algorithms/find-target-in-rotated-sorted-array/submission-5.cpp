class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
    int findMinIdx(vector<int> &nums) {
        if (nums.front() < nums.back()) return nums[0];

        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            cout << "low : " << low << " high : " << high << " mid : " << mid << endl;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }

        return high;
    }
    int search(vector<int>& nums, int target) {
        if (nums.front() <= nums.back()) return bs(nums, 0, nums.size() - 1, target);

        int idx = findMinIdx(nums);
        cout << "min idx : " << idx << endl;
        if (target > nums.back()) return bs(nums, 0, idx - 1, target);
        else return bs(nums, idx, nums.size() - 1, target);
    }
};
