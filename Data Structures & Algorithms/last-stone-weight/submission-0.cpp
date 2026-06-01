class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, greater<int>> max_heap;

        for (int weight : stones) max_heap.insert(weight);

        while(max_heap.size() > 1) {
            int x = *max_heap.begin();
            max_heap.erase(max_heap.begin());
            int y = *max_heap.begin();
            max_heap.erase(max_heap.begin());
            
            if (x == y) continue;
            
            max_heap.insert(x - y);
        }

        return (max_heap.size()) ? *max_heap.begin() : 0;
    }
};
