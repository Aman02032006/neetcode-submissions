class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m, left_elem = (m + n + 1) / 2;
        
        while (low <= high) {
            int pX = low + (high - low) / 2;
            int pY = left_elem - pX;

            int ML1 = (pX == 0) ? INT_MIN : nums1[pX - 1];
            int MR1 = (pX == m) ? INT_MAX : nums1[pX];
            int ML2 = (pY == 0) ? INT_MIN : nums2[pY - 1];
            int MR2 = (pY == n) ? INT_MAX : nums2[pY];

            if (ML1 <= MR2 && ML2 <= MR1) {
                if ((m + n) % 2 == 1) return max(ML1, ML2);
                else return (max(ML1, ML2) + min(MR1, MR2)) / 2.0;
            }
            else if (ML1 > MR2) high = pX - 1;
            else low = pX + 1;
        }

        return 0.0;
    }
};