
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    int boatload(vector<int> &arr){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int result = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n / 2; i++){
            int load = arr[i] + arr[n - i - 1];
            ans = max(load, result);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {70, 50, 80, 60, 40, 90};

    cout << s.boatload(arr);

    return 0;
}