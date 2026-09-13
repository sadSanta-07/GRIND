class Solution {
public:
    int shadowPairs(vector<int>& nums) {
        int n = nums.size();
        const int B = 700;
        int blocks = (n + B - 1) / B;

        vector<vector<int>> vals(blocks);
        vector<vector<vector<int>>> chains(blocks);

        for (int b = 0; b < blocks; b++) {
            int L = b * B;
            int R = min(n, L + B);

            vals[b] = vector<int>(nums.begin() + L, nums.begin() + R);
            sort(vals[b].begin(), vals[b].end());
            vals[b].erase(unique(vals[b].begin(), vals[b].end()), vals[b].end());

            chains[b].resize(vals[b].size() + 1);

            for (int t = 0; t <= (int)vals[b].size(); t++) {
                int limit = t == (int)vals[b].size()
                    ? INT_MAX
                    : vals[b][t];

                int mx = INT_MIN;
                auto& cur = chains[b][t];

                for (int i = R - 1; i >= L; i--) {
                    if (nums[i] < limit && nums[i] >= mx) {
                        cur.push_back(nums[i]);
                        mx = nums[i];
                    }
                }
            }
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int y = nums[j];
            int mx = INT_MIN;

            int b = j / B;
            int L = b * B;

            for (int i = j - 1; i >= L; i--) {
                if (nums[i] < y && nums[i] >= mx) {
                    ans++;
                    mx = nums[i];
                }
            }

            for (b--; b >= 0; b--) {
                int t = lower_bound(vals[b].begin(), vals[b].end(), y) - vals[b].begin();
                auto& cur = chains[b][t];

                int p = lower_bound(cur.begin(), cur.end(), mx) - cur.begin();

                ans += (int)cur.size() - p;

                if (!cur.empty())
                    mx = max(mx, cur.back());
            }
        }

        return (int)ans;
    }
};