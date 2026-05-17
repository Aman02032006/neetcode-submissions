class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int max_area = 0;
        while (i < n && j < n && i <= j) {
            max_area = max(max_area, min(heights[j], heights[i]) * (j - i));
            if (heights[i] <= heights[j]) i++;
            else j--;
        }

        return max_area;
    }
};
