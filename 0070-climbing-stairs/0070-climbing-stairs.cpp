class Solution {
public:
    unordered_map<int, int> dp;
    int solve(int i, int n) {
        if (i == n) {
            return 1;
        }
        if (i > n) {
            return 0;
        }
        if (dp.find(i) != dp.end())
            return dp[i];

        int a = solve(i + 1, n);
        int b = solve(i + 2, n);
        int ans = a + b;
        dp[i] = ans;
        return ans;
    }
    int climbStairs(int n) {
        int i = 0;
        return solve(i, n);
    }
};