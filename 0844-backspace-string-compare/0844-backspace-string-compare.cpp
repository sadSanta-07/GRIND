class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                temp.push_back(s[i]);
            } else if (!temp.empty()) {
                temp.pop_back();
            }
        }
        s = temp;
        temp.clear();
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') {
                temp.push_back(t[i]);
            } else if (!temp.empty()) {
                temp.pop_back();
            }
        }
        t = temp;
        if (s == t) {
            return true;
        }
        return false;
    }
};