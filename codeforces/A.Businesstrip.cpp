#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    cin >> k;

    if (k == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> a(12);

    for (int i = 0; i < 12; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0;
    int count = 0;

    for (int i = 0; i < 12; i++)
    {
        sum += a[i];
        count++;

        if (sum >= k)
        {
            cout << count << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}