#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void WayTooLongWords(vector<string>& arr)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].size() > 10)
            {
                cout << arr[i][0]<< arr[i].size() - 2  << arr[i][arr[i].size() - 1]  << endl;
            }
            else
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    obj.WayTooLongWords(arr);

    return 0;
}