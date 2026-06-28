#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl;";
    string s3 = "zxcvbnm,./";

    unordered_map<char, pair<string, int>> mp;

    for (int i = 0; i < s1.size(); i++)
        mp[s1[i]] = {s1, i};

    for (int i = 0; i < s2.size(); i++)
        mp[s2[i]] = {s2, i};

    for (int i = 0; i < s3.size(); i++)
        mp[s3[i]] = {s3, i};

    char dir;
    cin >> dir;

    string s, res;
    cin >> s;

    for (char ch : s)
    {
        auto p = mp[ch];
        string row = p.first;
        int idx = p.second;
        res += (dir == 'R') ? row[idx - 1] : row[idx + 1];
    }

    cout << res << endl;

    return 0;
}