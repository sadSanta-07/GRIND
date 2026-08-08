class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        for (int i = 0; i < magazine.size(); i++) {
            have[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {

            have[ransomNote[i]]--;
            if (have[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};