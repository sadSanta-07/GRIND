class Solution {
public:

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }
        int sum(int idx) {
            int res = 0;

            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }

            return res;
        }
    };

    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());

        vals.erase(
            unique(vals.begin(), vals.end()),
            vals.end()
        );

        auto getRank = [&](int x) {
            return lower_bound(
                vals.begin(),
                vals.end(),
                x
            ) - vals.begin() + 1;
        };

        Fenwick fw(vals.size());
        stack<int> st;

        long long ans = 0;

        for (int j = 0; j < n; j++) {

            int x = nums[j];
            while (!st.empty() &&
                   nums[st.top()] > x) {

                fw.add(
                    getRank(nums[st.top()]),
                    -1
                );

                st.pop();
            }
            int rank = getRank(x);

            ans += fw.sum(rank - 1);

            st.push(j);

            fw.add(rank, 1);
        }

        return ans;
    }
};