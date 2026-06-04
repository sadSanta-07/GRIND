#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    int selectionShift(vector<int> &arr){
        int n = arr.size();
        int shifts = 0;

        for (int i = 0; i < n; ++i){
            int curr = i;
            for (int j = i + 1; j < n; ++j){
                if (arr[j] < arr[curr]){
                    curr = j;
                }
            }
            if (curr != i){
                swap(arr[i], arr[curr]);
                shifts++;
            }
        }
        return shifts;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {64, 25, 12, 22, 11};
    int swaps = s.selectionShift(arr);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    cout << swaps << endl;
    return 0;
}