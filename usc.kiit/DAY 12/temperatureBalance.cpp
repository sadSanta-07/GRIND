#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
public:
    void tempbal(vector<int> &arr){
        sort(arr.begin(), arr.end());

        int start = 0;
        int end = arr.size() - 1;
        int minSum = INT_MAX;
        int ans1, ans2;
        while (start < end){
            int sum = arr[start] + arr[end];

            if (abs(sum) < minSum){
                minSum = abs(sum);
                ans1 = arr[start];
                ans2 = arr[end];
            }if (sum < 0)
                start++;
            else
                end--;
        }
        cout << ans1 << " " << ans2 << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution obj;
    obj.tempbal(arr);
    return 0;
}