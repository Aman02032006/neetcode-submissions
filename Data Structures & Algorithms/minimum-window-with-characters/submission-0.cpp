class Solution {
public:
    int idx (char ch) {
        if (ch >= 'a') return (ch - 'a') + 26;
        else return ch - 'A';
    } 

    string minWindow(string s, string t) {
        int n = s.size();

        vector<int> freqS(52, 0), freqT(52, 0);
        int charsT = 0;
        for (char ch : t) {
            if (freqT[idx(ch)] == 0) charsT++;
            freqT[idx(ch)]++;
        }

        int l = 0, r = 0;
        int matches = 0;

        int min_len = 1e9;
        int start = -1; 

        while (r < n) {
            char curr = s[r];
            freqS[idx(curr)]++;

            if (freqT[idx(curr)] && freqS[idx(curr)] == freqT[idx(curr)]) matches++;

            while (matches == charsT) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start = l;
                }

                freqS[idx(s[l])]--;

                if (freqT[idx(s[l])] && freqS[idx(s[l])] < freqT[idx(s[l])]) matches--;
                l++;
            }
            r++;
        }

        return start == -1 ? "" : s.substr(start, min_len);
    }
};
