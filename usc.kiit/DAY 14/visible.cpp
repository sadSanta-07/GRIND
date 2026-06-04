#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    int visible(vector<int> &arr){
        int n = arr.size();
        int left = 0;
        int right = arr.size() - 1;
        int ans = 0;
        while (left < right){
            int score = min(arr[left], arr[right]) * (right - left);
            ans = max(ans, score);
            if (arr[left] > arr[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3};

    cout << s.visible(arr);

    return 0;
}