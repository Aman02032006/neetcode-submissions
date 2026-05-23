class Solution {
public:
    long long hrs_required(vector<int>& piles, int k) {
        long long hours = 0;
        for(int pile : piles) {
            if (pile % k) hours += (pile / k) + 1;
            else hours += (pile / k);
        }

        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = hrs_required(piles, mid);

            if (hours > h) low = mid + 1;
            if (hours <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }

        return ans;
    }
};