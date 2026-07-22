class Solution {
public:
    int characterReplacement(string s, int k) {
        char maxx = 'A';
        for (char it : s)
            maxx = max(maxx, it);
        int final = 0;
        for (char i = 'A'; i <= maxx; i++) {
            int l = 0, r = 0, cnt = 0, mx = 0;
            while (r < s.size()) {
                if (s[r] != i)
                    cnt++;
                if (cnt > k) {
                    if (s[l] != i)
                        cnt--;
                    l++;
                }
                mx = max(mx, r - l + 1);
                r++;
            }
            final = max(final, mx);
        }
        return final;
    }
};