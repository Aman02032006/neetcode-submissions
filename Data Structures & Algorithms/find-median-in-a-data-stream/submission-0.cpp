class MedianFinder {
    int count;
    int opt_size;
    multiset<int> heap;
public:
    MedianFinder() {
        count = 0;
        opt_size = 1;
    }
    
    void addNum(int num) {
        count++;
        opt_size = count - max(0, count / 2 - 1);

        heap.insert(num);
        if (heap.size() > opt_size) heap.erase(heap.begin());
    }
    
    double findMedian() {
        if (heap.size() == 1) return (double)*heap.begin();

        int x = *heap.begin();
        heap.erase(heap.begin());
        int y = *heap.begin();
        heap.insert(x);

        if (count % 2) return (double)y;
        else return ((double)x + y) / 2.0;
    }
};
