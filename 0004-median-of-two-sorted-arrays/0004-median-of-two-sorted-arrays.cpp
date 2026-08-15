class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int total = m + n;
        int leftSize = (total + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = leftSize - i;

            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];

            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {

                int leftMax = max(Aleft, Bleft);
                int rightMin = min(Aright, Bright);
                if (total % 2 == 1) {
                    return leftMax;
                }
                return (leftMax + rightMin) / 2.0;
            } else if (Aleft > Bright) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};