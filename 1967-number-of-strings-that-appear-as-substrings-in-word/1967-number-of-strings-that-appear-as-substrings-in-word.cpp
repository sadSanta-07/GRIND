class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (string ch : patterns) {
            if (word.contains(ch)) {
                count++;
            }
        }
        return count;
    }
};