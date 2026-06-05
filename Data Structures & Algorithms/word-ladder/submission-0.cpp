class Solution {
    bool valid_edge(string a, string b) {
        int diff = 0;
        for (int i = 0 ; i < a.size() ; i++ ){
            if (a[i] != b[i]) diff++;
        }

        return (diff == 1);
    }    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int start = -1, end = -1;
        for (int i = 0 ; i < wordList.size() ; i++) {
            if (wordList[i] == beginWord) start = i;
            if (wordList[i] == endWord) end = i;
        }        

        if (start == -1) {
            wordList.push_back(beginWord);
            start = wordList.size() - 1;
        }

        if (end == -1) return 0;

        int n = wordList.size();
        vector<vector<int>> adj(n);
        for (int i = 0 ; i < n ; i++) {
            if (beginWord == wordList[i]) start = i;
            if (endWord == wordList[i]) end = i;
            for (int j = 0 ; j < n ; j++) {
                if (valid_edge(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> dist(n, 0);
        queue<int> q;
        q.push(start);
        dist[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int w : adj[u]) {
                if (dist[w]) continue;
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }

        return dist[end];
    }
};
