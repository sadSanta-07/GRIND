#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    void reverseWords(string s)
    {
        vector<string> words;
        int n = s.size();
        int i = 0;
        while (i < n){
            while (i < n && s[i] == ' '){
                i++;
            }
            string word = "";
            while (i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            if (!word.empty()){
                words.push_back(word);
            }
        }
        for (int i = words.size() - 1; i >= 0; i--){
            cout << words[i];

            if (i > 0){
                cout << " ";
            }
        }
    }
};

int main()
{
    string s;
    getline(cin, s);

    Solution obj;
    obj.reverseWords(s);

    return 0;
}