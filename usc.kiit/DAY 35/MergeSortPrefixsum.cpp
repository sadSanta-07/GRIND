#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int eligible(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        if (sum >= k)
        {
            count++;
        }
        sum += arr[i];
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << eligible(arr, n, k);

    return 0;
}