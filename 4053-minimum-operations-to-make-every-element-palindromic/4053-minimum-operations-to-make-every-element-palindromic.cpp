class Solution {
public:
    long long makePal(long long x, bool odd) {
        long long res = x;

        if (odd)
            x /= 10;

        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    long long minOperations(vector<int>& nums) {

        vector<long long> evenpal;
        vector<long long> oddpal;

        for (int len = 1; len <= 9; len++) {

            int half = (len + 1) / 2;

            long long start = 1;
            for (int i = 1; i < half; i++)
                start *= 10;

            long long end = start * 10 - 1;

            for (long long x = start; x <= end; x++) {

                long long pal;

                if (len % 2 == 1) {
                    pal = makePal(x, true);
                } else {
                    pal = makePal(x, false);
                }
                if (pal <= 1000000000LL) {

                    if (pal % 2 == 0)
                        evenpal.push_back(pal);
                    else
                        oddpal.push_back(pal);
                }
            }
        }

        long long ans = 0;

        for (long long x : nums) {

            const auto& pals = (x % 2 == 0) ? evenpal : oddpal;

            auto it = lower_bound(pals.begin(), pals.end(), x);

            long long best = LLONG_MAX;

            if (it != pals.end()) {
                best = min(best, *it - x);
            }

            if (it != pals.begin()) {
                --it;
                best = min(best, x - *it);
            }

            ans += best / 2;
        }

        return ans;
    }
};