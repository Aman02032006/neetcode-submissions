class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;
            if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int low = 0, high = matrix.size() - 1, idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] < target) {
                idx = max(idx, mid);
                low = mid + 1;
            }
            else if (matrix[mid][0] == target) return true;
            else high = mid - 1;
        }

        return search(matrix[idx], target);
    }
};
