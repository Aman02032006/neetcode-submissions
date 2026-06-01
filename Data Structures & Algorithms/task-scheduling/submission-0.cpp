class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto task : tasks) freq[task - 'A']++;

        priority_queue<int> order;
        queue<pair<int, int>> q;

        for (auto f : freq) {
            if (f) order.push(f);
        }

        int time = 0;
        while (!q.empty() || !order.empty()) {
            time++;
            
            if (!order.empty()) {
                int count = order.top();
                order.pop();
                count--;

                if (count) q.push({count, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                order.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
