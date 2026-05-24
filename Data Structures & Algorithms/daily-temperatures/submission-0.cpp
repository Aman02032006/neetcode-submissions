class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> next(temperatures.size(), 0);
        for (int i = 0 ; i < temperatures.size() ; i++) {
            if (temp.empty()) temp.push(i);
            else {
                while (!temp.empty() && temperatures[temp.top()] < temperatures[i]) {
                    next[temp.top()] = i - temp.top();
                    temp.pop();
                }
                temp.push(i);
            }
        }

        return next;
    }
};
