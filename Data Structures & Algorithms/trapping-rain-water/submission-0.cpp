class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> water(n);

        int max_height = 0;
        for (int i = 0 ; i < n ; i++) {
            max_height = max(max_height, height[i]);
            water[i] = max_height - height[i];
        }

        max_height = 0;
        int ans = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            max_height = max(max_height, height[i]);
            water[i] = min(water[i], max_height - height[i]);
            ans += water[i];
        }

        return ans;
    }
};
