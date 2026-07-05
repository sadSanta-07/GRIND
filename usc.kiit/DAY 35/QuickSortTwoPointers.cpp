#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eligible(vector<int> &arr, int n, int x)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n - 1;
    int cunt = 0;
    while (left < right)
    {
        int psum = arr[left] + arr[right];

        if (psum > x)
        {
            right--;
        }
        else if (psum < x)
        {
            left++;
        }
        else
        {
            cunt++;
            int lval = arr[left];
            int rval = arr[right];

            while (left < right && arr[left] == lval)
                left++;

            while (left < right && arr[right] == rval)
                right--;
        }
    }
    return cunt;
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << eligible(arr, n, x);

    return 0;
}