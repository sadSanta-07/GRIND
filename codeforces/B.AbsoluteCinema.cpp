#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long a[n];
        long long b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        long long sum = 0;
        long long best = 0;

        for (int i = 0; i < n; i++)
        {
            long long mx = max(a[i], b[i]);
            long long mn = min(a[i], b[i]);

            sum += mx;

            if (mn > best)
            {
                best = mn;
            }
        }

        cout << sum + best << endl;
    }

    return 0;
}