#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;
vector<string> mp = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void solve(int idx, string &digits, string &curr)
{
    if(idx == digits.size())
    {
        ans.push_back(curr);
        return;
    }

    string letters = mp[digits[idx] - '0'];

    for(char ch : letters)
    {
        curr.push_back(ch);

        solve(idx + 1, digits, curr);

        curr.pop_back();
    }
}

int main()
{
    string digits;
    cin >> digits;

    string curr = "";

    solve(0, digits, curr);

    for(string s : ans)
        cout << s << " ";

    return 0;
}