#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int search(vector<int> &arr, int n, int k)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k)
            return mid + 1;
        if (arr[mid] > k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, m, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<int>());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        int rank = search(arr, n, k);

        if (rank == -1)
            cout << "No Rank\n";
        else
            cout << "Rank " << rank << '\n';
    }

    return 0;
}