#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int Team(vector<vector<int>> &arr, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < 3; j++)
            {
                count += arr[i][j];
            }
            if (count >= 2)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution obj;
    cout << obj.Team(arr, n);

    return 0;
}