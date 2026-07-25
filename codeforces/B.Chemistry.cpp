// 1883B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        unordered_map<char, int> mp;

        for (char ch : s)
        {
            mp[ch]++;
        }

        int odcnt = 0;

        for (auto it : mp)
        {
            if (it.second % 2)
                odcnt++;
        }

        if (odcnt <= k + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}