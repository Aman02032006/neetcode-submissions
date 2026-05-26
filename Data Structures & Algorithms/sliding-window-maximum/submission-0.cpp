class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int, greater<int>> maxHeap;
        vector<int> result;
        for (int i = 0 ; i < k ; i++) maxHeap.insert(nums[i]);
        result.push_back(*maxHeap.begin());

        for (int r = k ; r < n ; r++) {
            maxHeap.insert(nums[r]);
            auto it = maxHeap.find(nums[r - k]);
            if (it != maxHeap.end()) maxHeap.erase(it);

            result.push_back(*maxHeap.begin());
        }

        return result;
    }
};
