class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long long mx = nums[0];
        long long mn = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            long long curr = nums[i];

            if (curr < 0)
                swap(mx, mn);

            mx = max(curr, mx * curr);
            mn = min(curr, mn * curr);

            ans = max(ans, mx);
        }

        return ans;
    }
};