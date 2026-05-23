class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timemap;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].emplace_back(timestamp, value);
    }

    string findTimestamp(vector<pair<int, string>> v, int target) {
        if (target < v.front().first) return "";

        int low = 0, high = v.size() - 1, idx = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid].first <= target) {
                low = mid + 1;
                idx = max(idx, mid);
            }
            else high = mid - 1;
        }

        return v[idx].second;
    }
    
    string get(string key, int timestamp) {
        auto it = timemap.find(key);
        
        if (it == timemap.end()) return "";
        auto v = it->second;

        return findTimestamp(v, timestamp);
    }
};
