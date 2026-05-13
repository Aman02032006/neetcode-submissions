class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2, 0);
        unordered_map<int, int> idx;

        for (int i = 0 ; i < nums.size() ; i++) {
            if (i) {
                if (idx[nums[i]]) {
                    indices[0] = idx[nums[i]] - 1;
                    indices[1] = i;
                    break;
                }
            }

            idx[target - nums[i]] = i + 1;
        }

        return indices;
    }
};
