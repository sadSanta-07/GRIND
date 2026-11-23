class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        unordered_set<string> f(words.begin(),
                                words.end()); // Cleaner than map<string, int>

        if (f.find(end) == f.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({begin, 1}); // Use 1 for word count, 0 for edge/step count
        f.erase(begin);

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();

            string s = p.first;
            int val = p.second;

            if (s == end)
                return val;

            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (c == j)
                        continue;
                    s[i] = j;

                    if (f.find(s) != f.end()) {
                        q.push({s, val + 1});
                        f.erase(s);
                    }
                }
                s[i] = c; // Restore original character
            }
        }
        return 0;
    }
};