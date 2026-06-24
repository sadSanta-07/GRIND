// 200B

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution
{
public:
    double Drinks(vector<int> arr, int n)
    {
        double sum = 0;
        for (int k : arr)
        {
            sum += k;
        }
        return sum / n;
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fixed << setprecision(12);
    cout << obj.Drinks(arr, n) << "\n";

    return 0;
}