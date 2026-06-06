
// Ansuman and the Security Alarm Codes
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // int secalcod(vector<int> &arr)
    // {
    //     sort(arr.begin(), arr.end());

    //     for (int i = 0; i < arr.size() - 1; i++)
    //     {
    //         if (arr[i] == arr[i + 1])
    //         {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // optimize approach
    bool secalcod(vector<int> &arr)
    {
        unordered_set<int> vis;

        for (int i = 0; i < arr.size(); i++)
        {
            if (vis.count(arr[i]))
            {
                return true;
            }

            vis.insert(arr[i]);
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {1, 2, 2, 3, 4};

    cout << s.secalcod(arr);

    return 0;
}