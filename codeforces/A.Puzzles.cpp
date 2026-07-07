// 337A
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int puzzles(vector<int> arr, int p)
    {
        sort(arr.begin(), arr.end());
        int mn = INT_MAX;
        for (int i = 0; i <= arr.size() - p; i++)
        {
            mn = min(mn, arr[i + p - 1] - arr[i]);
        }
        return mn;
    }
};

int main()
{
    int p;
    cin >> p;
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.puzzles(arr, p);

    return 0;
}