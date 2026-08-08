class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        bool odd = false;
        int cnt = 0;
        for (auto x : mp) {
            cnt += (x.second / 2) * 2;
            if (x.second % 2 == 1) {
                odd = true;
            }
        }
        if (odd)
            cnt++;

        return cnt;
    }
};