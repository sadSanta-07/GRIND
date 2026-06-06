#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    void analyzeString(string s) {

        int vowels = 0;
        int consonants = 0;
        int words = 1;
        for(int i = 0; i < s.length(); i++) {
            char ch = tolower(s[i]);
            if(ch == ' ') {
                words++;
            }
            if(isalpha(ch)) {
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
                    vowels++;
                }
                else {
                    consonants++;
                }
            }
        }
        cout << "Total Vowels: " << vowels << endl;
        cout << "Total Consonants: " << consonants << endl;
        cout << "Total Words: " << words << endl;
    }
};

int main() {
    string s;
    getline(cin, s);
    Solution obj;
    obj.analyzeString(s);
    return 0;
}