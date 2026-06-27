// 467A
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int accomodate(vector<pair<int, int>> arr, int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].first + 2 <= arr[i].second)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << obj.accomodate(arr, n);
    return 0;
}