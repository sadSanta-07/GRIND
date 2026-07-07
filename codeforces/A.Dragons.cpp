// 230A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void dragon(vector<pair<int, int>> arr, int s, int n)
    {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (s > arr[i].first)
            {
                s += arr[i].second;
            }
            else
            {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    }
};

int main()
{
    int s;
    cin >> s;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    Solution obj;
    obj.dragon(arr, s, n);

    return 0;
}