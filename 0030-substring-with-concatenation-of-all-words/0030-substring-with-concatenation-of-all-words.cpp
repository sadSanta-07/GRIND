class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> freq;

        for (string word : words)
            freq[word]++;

        vector<int> ans;

        int n = words.size();
        int wordsize = words[0].size();

        int len = s.size();

        for (int offset = 0; offset < wordsize; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> curr;

            for (int right = offset; right + wordsize <= len;
                 right += wordsize) {

                string word = s.substr(right, wordsize);

                if (freq.find(word) == freq.end()) {

                    curr.clear();
                    count = 0;
                    left = right + wordsize;

                } else {

                    curr[word]++;
                    count++;

                    while (curr[word] > freq[word]) {

                        string remove = s.substr(left, wordsize);

                        curr[remove]--;
                        left += wordsize;
                        count--;
                    }

                    if (count == n) {

                        ans.push_back(left);

                        string remove = s.substr(left, wordsize);
                        curr[remove]--;
                        left += wordsize;
                        count--;
                    }
                }
            }
        }

        return ans;
    }
};