#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string plcemntbur(vector<int> &arr, int n, int k, int x)
    {
        long long windowSum = 0;
        int zeroCount = 0;

        for (int i = 0; i < k; i++)
        {
            windowSum += arr[i];

            if (arr[i] == 0)
                zeroCount++;
        }
        if (windowSum >= x && zeroCount == 0)
            return "YES";

        for (int i = k; i < n; i++)
        {
            windowSum -= arr[i - k];

            if (arr[i - k] == 0)
                zeroCount--;

            windowSum += arr[i];

            if (arr[i] == 0)
                zeroCount++;

            if (windowSum >= x && zeroCount == 0)
                return "YES";
        }

        return "NO";
    }
};

int main()
{
    int n, k, x;

    cin >> n >> k >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.plcemntbur(arr, n, k, x);

    return 0;
}