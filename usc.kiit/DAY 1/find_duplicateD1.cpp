#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:

    bool duplicates(vector<int> &arr)
    {
        unordered_map<int, int> freq;

        for(int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;

            if(freq[arr[i]] == 2)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {78, 85, 91, 77, 88, 95};

    if (s.duplicates(arr))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}