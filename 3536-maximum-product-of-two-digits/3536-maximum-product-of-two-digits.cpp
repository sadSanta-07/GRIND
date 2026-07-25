class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        int first = 0;
        int second = 0;

        for (char c : s) {
            int digit = c - '0';

            if (digit > first) {
                second = first;
                first = digit;
            } else if (digit > second) {
                second = digit;
            }
        }

        return first * second;
    }
};