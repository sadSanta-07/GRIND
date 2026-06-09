#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void bitxor(vector<int> &arr)
    {
        int xr = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            xr = xr ^ arr[i];
        }
        if (xr == 0)
        {
            cout << "BALANCED" << endl;
        }
        else
        {
            cout << "UNBALANCED" << endl;
        }
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    obj.bitxor(arr);

    return 0;
}