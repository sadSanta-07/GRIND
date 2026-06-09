#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortedSquares(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;

        int idx = n - 1;

        while (left <= right)
        {
            int leftsqr = arr[left] * arr[left];
            int rightsqr = arr[right] * arr[right];

            if (leftsqr > rightsqr)
            {
                ans[idx] = leftsqr;
                left++;
            }
            else
            {
                ans[idx] = rightsqr;
                right--;
            }

            idx--;
        }

        for (int x : ans)
        {
            cout << x << " ";
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

    obj.sortedSquares(arr);

    return 0;
}