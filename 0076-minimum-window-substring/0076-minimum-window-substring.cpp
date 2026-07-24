class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if (t.length() > n)
            return "";

        unordered_map<char, int> mp;

        // store
        for (char& ch : t) {
            mp[ch]++;
        }
        int requiredcnt = t.length();
        int i = 0, j = 0;

        int min = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            if (mp[ch] > 0) {
                requiredcnt--;
            }
            mp[ch]--;

            while (requiredcnt == 0) {
                // shrink

                int winsize = j - i + 1;

                if (min > winsize) {
                    min = winsize;
                    start_i = i;
                }
                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    requiredcnt++;
                }
                i++;
            }
            j++;
        }
        return min == INT_MAX ? "" : s.substr(start_i, min);
    }
};