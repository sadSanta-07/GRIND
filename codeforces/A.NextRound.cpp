#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nextround(vector<int>& arr, int n, int k)
    {
        int count = 0;
        int kthScore = arr[k - 1];

        for(int i = 0; i < n; i++)
        {
            if(arr[i] >= kthScore && arr[i] > 0)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.nextround(arr, n, k);

    return 0;
}