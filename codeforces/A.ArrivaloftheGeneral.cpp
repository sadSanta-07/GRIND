// 144A
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    int genral(vector<int> &arr, int n)
    {
        int maxi = 0, mini = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[maxi])
                maxi = i;
            if (arr[i] <= arr[mini])
                mini = i;
        }

        if (maxi > mini)
        {
            return maxi + (n - 1 - mini) - 1;
        }
        else
        {
            return maxi + (n - 1 - mini);
        }
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << obj.genral(arr, n) << "\n";

    return 0;
}