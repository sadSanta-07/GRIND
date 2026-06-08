#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    void anagram(string s1, string s2) {

        if (s1.size() != s2.size()) {
            cout << "No";
            return;
        }

        int freq[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                cout << "No";
                return;
            }
        }

        cout << "Yes";
    }
};

int main() {

    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    Solution obj;

    obj.anagram(s1, s2);

    return 0;
}