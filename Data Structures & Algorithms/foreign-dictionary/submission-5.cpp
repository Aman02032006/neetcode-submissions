class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int k = words.size();
        int unique = 0;

        vector<vector<int>> adj(26);
        vector<int> deg(26, -1);
        for (string w : words) {
            for (char ch : w) {
                if (deg[ch - 'a'] == -1) unique++;
                deg[ch - 'a'] = 0;
            }
        }
        
        for (int i = 0; i < k - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int j = 0;
            while (j < s1.size() && j < s2.size() && s1[j] == s2[j]) j++;

            if (j >= min(s1.size(), s2.size()) && s1.size() > s2.size()) return "";
            else if (j < min(s1.size(), s2.size())) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                deg[s2[j] - 'a']++;
            }
        }

        queue<int> q;
        string res = "";
        for (int i = 0 ; i < 26 ; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        } 

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res += (char)('a' + u);

            for (int w : adj[u]) {
                deg[w]--;
                if (deg[w] == 0) {
                    q.push(w);
                }
            }
        }

        return (res.size() == unique ? res : "");
    }
};
