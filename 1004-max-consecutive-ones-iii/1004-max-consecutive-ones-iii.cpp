class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntzer = 0;
        int l = 0;
        int mx = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] == 0) {
                cntzer++;
            }

            while (cntzer > k) {
                if (nums[l] == 0) {
                    cntzer--;
                }
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};