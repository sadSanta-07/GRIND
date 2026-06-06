#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int prefixsum(vector<int> &arr, int x)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum > x)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {3, 4, 5, 2, 8, 1};

    cout << s.prefixsum(arr, 20);

    return 0;
}