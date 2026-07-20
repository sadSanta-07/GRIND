class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;

        vector<int> temp;
        for (auto& row : grid) {
            for (int x : row)
                temp.push_back(x);
        }
        k %= size;
        vector<vector<int>> ans(m, vector<int>(n));
        int ind = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int oldIndex = (ind - k + size) % size;
                ans[i][j] = temp[oldIndex];
                ind++;
            }
        }
        return ans;
    }
};