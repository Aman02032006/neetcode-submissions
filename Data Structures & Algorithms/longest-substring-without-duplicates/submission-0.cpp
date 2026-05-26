class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size();
        unordered_map<char, bool> present;
        int max_window = 0;
        while (i < n && j < n) {
            while (present[s[j]]) {
                present[s[i]] = false;
                i++;
            }
            present[s[j]] = true;
            max_window = max(max_window, j - i + 1);
            j++;
        }

        return max_window;
    }
};
