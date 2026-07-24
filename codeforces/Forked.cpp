// 1904A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int xK, yK;
        cin >> xK >> yK;

        int xQ, yQ;
        cin >> xQ >> yQ;

        vector<pair<int, int>> k, q;

        int dx[] = {a, a, -a, -a, b, b, -b, -b};
        int dy[] = {b, -b, b, -b, a, -a, a, -a};

        for (int i = 0; i < 8; i++)
        {
            pair<int, int> kp = {xK + dx[i], yK + dy[i]};
            pair<int, int> qp = {xQ + dx[i], yQ + dy[i]};

            bool found = false;
            for (auto x : k)
            {
                if (x == kp)
                    found = true;
            }
            if (!found)
                k.push_back(kp);

            found = false;
            for (auto x : q)
            {
                if (x == qp)
                    found = true;
            }
            if (!found)
                q.push_back(qp);
        }

        int ans = 0;

        for (auto x : k)
        {
            for (auto y : q)
            {
                if (x == y)
                    ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}