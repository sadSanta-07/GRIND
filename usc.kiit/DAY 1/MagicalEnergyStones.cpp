#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    void stones(vector<int> &arr)
    {
        int j = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

int main()
{
    Solution s;

    vector<int> arr = {1,0,4,0,5,2,0};

    s.stones(arr);

    for(int x : arr)
    {
        cout << x << " ";
    }
}