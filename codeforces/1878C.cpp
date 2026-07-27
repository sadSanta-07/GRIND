// 1878C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        long long minsum = k * (k + 1) / 2;
        long long m1 = n * (n + 1) / 2;
        long long m2 = (n - k) * (n - k + 1) / 2;
        long long maxsum = m1 - m2;

        if (minsum <= x && x <= maxsum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}