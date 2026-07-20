#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<long long> pref(n);

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if (i == 0)
            pref[i] = x;
        else
            pref[i] = pref[i - 1] + x;
    }

    while (m--)
    {
        long long x;
        cin >> x;

        // Find the first dormitory whose ending room >= x
        int dorm = lower_bound(pref.begin(), pref.end(), x) - pref.begin();

        long long before = 0;

        if (dorm > 0)
            before = pref[dorm - 1];

        long long room = x - before;

        cout << dorm + 1 << " " << room << "\n";
    }

    return 0;
}