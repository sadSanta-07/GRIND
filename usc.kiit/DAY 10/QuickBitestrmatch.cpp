#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void quicmbite(vector<int> &arr, int m){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;
            while (left < right){
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == m){
                    cout << "YES" << endl;
                    return;
                }else if (sum < m){
                    left++;
                }else{
                    right--;
                }
            }
        }
        cout << "NO" << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "target mya hai" << endl;
    cin >> m;
    Solution obj;
    obj.quicmbite(arr, m);
    return 0;
}