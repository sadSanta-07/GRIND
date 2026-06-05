
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int secLar(vector<int>& arr)
    {
        int lar = INT_MIN;
        int secLar = INT_MIN;

        for(int x : arr)
        {
            if(x > lar)
            {
                secLar = lar;
                lar = x;
            }
            else if(x > secLar && x != lar)
            {
                secLar = x;
            }
        }

        return secLar;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {0,200};

    cout << s.secLar(arr);

    return 0;
}