#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int shiftcount(vector<int> &arr){
        int n = arr.size();
        int shift = 0;
        for (int i = 1; i < n; ++i){
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j = j - 1;
                shift++;
            }
            arr[j + 1] = key;
        }
        return shift;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {1, 2, 4, 5, 3, 6};

    cout << s.shiftcount(arr);

    return 0;
}