class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        map <int, float> time;
        vector<float> times;
        for (int i = 0 ; i < n ; i++) {
            time[position[i]] = (float)(target - position[i]) / speed[i];
        }

        for (auto p : time) times.push_back(p.second);

        int fleets = 0;
        int i = 0;
        while (i < n) {
            int max_idx = i, j = i;
            float curr = times[i];
            while (j < n) {
                if (times[j] >= curr) {
                    max_idx = j;
                    curr = times[j];
                }
                j++;
            }
            i = max_idx + 1;
            fleets++;
        }

        return fleets;
    }
};
