class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int prod = 1;
        for (int r = 0; r < nums.size(); r++) {
            prod *= nums[r];

            while (prod >= k) {
                prod /= nums[l];
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }
};