class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;

        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (s.empty()) s.push(i);
            if (heights[s.top()] < heights[i]) {
                left[i] = s.top();
                s.push(i);
            }
        }
        while (!s.empty()) s.pop();

        for (int i = n - 1 ; i >= 0 ; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (s.empty()) s.push(i);
            else if (heights[s.top()] < heights[i]) {
                right[i] = s.top();
                s.push(i);
            }
        }

        int max_area = 0;

        for (int i = 0 ; i < n ; i++) {
            max_area = max(max_area, heights[i] * (right[i] - left[i] - 1));
        }

        return max_area;        
    }
};
