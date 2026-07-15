class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int n, int i, int free) {
        if (i == n)
            return 0;

        if (dp[i][free] != -1)
            return dp[i][free];

        if (free == 0)
            return dp[i][free] = solve(nums, n, i + 1, 1);

        int pick = nums[i] + solve(nums, n, i + 1, 0);
        int nopick = solve(nums, n, i + 1, 1);

        return dp[i][free] = max(pick, nopick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(nums, n, 0, 1);
    }
};