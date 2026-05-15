class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
        string str = "";
        for (char c : s) {
            if (isalnum(c)) str += c;
        }

        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
