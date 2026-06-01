class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> heap;
        for (int num : nums) {
            heap.insert(num);
            if (heap.size() > k) heap.erase(heap.begin());
        }

        return *heap.begin();
    }
};
