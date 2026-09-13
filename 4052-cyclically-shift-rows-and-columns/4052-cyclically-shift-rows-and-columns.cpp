class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ncol = (j - rowShift[i] + n) % n;
                temp[i][ncol] = grid[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                int nrow = (i - colShift[j] + n) % n;
                ans[nrow][j] = temp[i][j];
            }
        }
        return ans;
    }
};