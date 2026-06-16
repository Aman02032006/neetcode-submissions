class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        if (n > 0) res[1] = 1;
        int ptr = 1;
        for (int i = 2; i <= n; i++) {
            if ((i & (i - 1)) == 0) ptr <<= 1;
            res[i] = 1 + res[i - ptr];
        }

        return res;
    }
};
