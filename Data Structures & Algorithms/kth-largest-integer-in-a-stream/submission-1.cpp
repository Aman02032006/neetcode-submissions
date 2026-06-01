class KthLargest {
    int k;
    multiset<int> min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            min_heap.insert(num);
            if (min_heap.size() > this->k) min_heap.erase(min_heap.begin());
        }
    }
    
    int add(int val) {
        min_heap.insert(val);
        if (min_heap.size() > this->k) min_heap.erase(min_heap.begin());

        return *min_heap.begin();
    }
};
