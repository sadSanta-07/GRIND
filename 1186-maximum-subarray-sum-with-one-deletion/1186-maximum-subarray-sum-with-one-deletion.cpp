class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        long long power = -1e18;
        long long nopower = arr[0];

        long long res = arr[0];

        for (int i = 1; i < n; i++) {

            int x = arr[i];

            long long v1 = x;
            long long v2 = nopower + x;
            long long v3 = power + x;
            long long v4 = nopower;

            res = max(res, max(max(v1, v2), max(v3, v4)));

            nopower = max(v1, v2);
            power = max(v3, v4);
        }

        return res;
    }
};