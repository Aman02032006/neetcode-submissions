class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (auto s : strs) {
            encoded_string += s;
            encoded_string += "#!@!#";
        }
        cout << encoded_string << endl;

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;

        string str = "";
        for (int i = 0 ; i < s.size() ; i++) {
            char c = s[i];
            if (s[i] == '#' && s[i + 1] == '!' && s[i + 2] == '@' && s[i + 3] == '!' && s[i + 4] == '#') {
                decoded_strings.push_back(str);
                str = "";
                i += 4;
            }
            else str += c;
        }

        return decoded_strings;
    }
};
