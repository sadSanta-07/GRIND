class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long nw = 0;
        string s = to_string(n);
        for (char c : s) {
            int digit = c - '0';
            if (digit != 0) {
                sum += digit;
                nw = nw * 10;
                nw = nw + digit;
            }
        }
        return (nw * sum);
    }
};