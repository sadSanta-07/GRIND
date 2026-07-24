class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (char ch : s1)
            mp[ch]++;
        int n = s2.size();
        int requiredcnt = s1.length();
        int i = 0, j = 0;
        while (j < n) {
            char ch = s2[j];

            if (mp[ch] > 0)
                requiredcnt--;

            mp[ch]--;
            j++;

            while (j - i > s1.size()) {
                char remove = s2[i];

                if (mp[remove] >= 0)
                    requiredcnt++;
                mp[remove]++;
                i++;
            }
            
            if (requiredcnt == 0)
                return true;
        }
        return false;
    }
};