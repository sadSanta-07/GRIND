#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    int uniqueNum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        uniqueNum ^= arr[i];
    }

    sort(arr.begin(), arr.end());

    int position = lower_bound(arr.begin(), arr.end(), uniqueNum) - arr.begin() + 1;

    cout << uniqueNum << " " << position << '\n';

    return 0;
}