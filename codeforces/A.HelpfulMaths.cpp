// 339A

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string HelpfulMaths(string s1)
    {
        string digits;
        for (char c : s1) if (c >= '1' && c <= '9') digits.push_back(c);
        sort(digits.begin(), digits.end());
        string res;
        for (size_t i = 0; i < digits.size(); ++i) {
            if (i) res.push_back('+');
            res.push_back(digits[i]);
        }
        return res;
    }
};

int main()
{
    string s1;
    if (!(cin >> s1)) return 0;
    Solution sol;
    cout << sol.HelpfulMaths(s1) << '\n';
    return 0;
}