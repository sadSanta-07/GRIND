#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxsubarr(vector<int> &arr, int n, int w)
    {
        int l = 0;
        int mx = 0;
        int sum = 0;

        for (int r = 0; r < n; r++)
        {
            sum += arr[r];

            while (sum > w)
            {
                sum -= arr[l];
                l++;
            }

            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};

int main()
{
    Solution obj;
    int n, w;
    cin >> n;
    cin >> w;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = obj.maxsubarr(arr, n, w);
    cout << res << endl;

    return 0;
}