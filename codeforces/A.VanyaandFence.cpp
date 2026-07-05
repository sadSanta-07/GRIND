// 677A

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int vanayafense(vector<int> arr, int n, int h)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= h)
            {
                sum += 1;
            }
            else
            {
                sum += 2;
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    int h;
    cin >> h;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.vanayafense(arr, n, h);

    return 0;
}