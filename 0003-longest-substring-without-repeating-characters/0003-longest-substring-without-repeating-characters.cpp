class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0;
        int mx = 0;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};