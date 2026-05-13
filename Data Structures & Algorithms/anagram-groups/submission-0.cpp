class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_strings;
        for (string s : strs) {
            sort(s.begin(), s.end());
            sorted_strings.push_back(s);
        }

        vector<bool> taken(strs.size(), false);

        vector<vector<string>> result;
        for (int i = 0 ; i < strs.size() ; i++) {
            if (taken[i]) continue;
            taken[i] = true;
            vector<string> anagrams;
            anagrams.push_back(strs[i]);

            for (int j = i + 1 ; j < strs.size() ; j++) {
                if (sorted_strings[i] == sorted_strings[j]) {
                    taken[j] = true;
                    anagrams.push_back(strs[j]);
                }
            }

            result.push_back(anagrams);
        }

        return result;
    }
};
