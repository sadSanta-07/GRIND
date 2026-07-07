#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<long long, int> mp;
    mp[0] = 1;

    long long prefix = 0;
    long long ans = 0;

    for (int x : arr)
    {
        prefix += x;

        if (mp.find(prefix - k) != mp.end())
        {
            ans += mp[prefix - k];
        }

        mp[prefix]++;
    }

    cout << ans << endl;

    return 0;
}