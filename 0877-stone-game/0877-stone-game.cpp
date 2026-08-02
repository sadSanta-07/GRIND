class Solution {
public:
    int solve(vector<int>& piles, int l, int r, int turn,
              vector<vector<vector<int>>>& dp) {

        if (l > r) {
            return 0;
        }

        if (dp[l][r][turn] != INT_MIN) {
            return dp[l][r][turn];
        }

        if (turn == 0) {
            // Alice wants to MAXIMIZE (Alice - Bob)

            int left = piles[l] + solve(piles, l + 1, r, 1, dp);

            int right = piles[r] + solve(piles, l, r - 1, 1, dp);

            return dp[l][r][turn] = max(left, right);
        }

        else {
            // Bob wants to MINIMIZE (Alice - Bob)

            int left = -piles[l] + solve(piles, l + 1, r, 0, dp);

            int right = -piles[r] + solve(piles, l, r - 1, 0, dp);

            return dp[l][r][turn] = min(left, right);
        }
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, INT_MIN)));

        int diff = solve(piles, 0, n - 1, 0, dp);

        return diff > 0;
    }
};