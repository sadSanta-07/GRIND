#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void levelling(vector<long long> &arr, int n)
    {
        long long pref = 0;
        long long mn = 1e18;

        for (int i = 0; i < n; i++)
        {
            pref += arr[i];

            mn = min(mn, pref / (i + 1));

            cout << mn << " ";
        }
    }
};

int main()
{
    int t;
    cin >> t;

    Solution s;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        s.levelling(arr, n);
    }

    return 0;
}