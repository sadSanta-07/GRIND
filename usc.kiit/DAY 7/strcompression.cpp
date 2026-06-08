#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    void decoder(string s1) {
        string s2 = "";
        int count = 1;
        for (int i = 0; i < s1.size(); i++) {
            while (i < s1.size() - 1 && s1[i] == s1[i + 1]) {
                count++;
                i++;
            }
            // Append character
            s2 += s1[i];
            // Append count
            s2 += to_string(count);
            count = 1;
        }
        cout << s2;
    }
};

int main() {

    string s1;

    getline(cin, s1);

    Solution obj;

    obj.decoder(s1);

    return 0;
}