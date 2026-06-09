#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longPrefix(vector<string> &arr)
    {
        string prefix = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            string current = arr[i];

            string temp = "";
            for (int j = 0; j < min(prefix.size(), current.size()); j++)
            {
                if (prefix[j] == current[j])
                {
                    temp += prefix[j];
                }
                else
                {
                    break;
                }
            }
            prefix = temp;

            if (prefix == "")
            {
                return "";
            }
        }

        return prefix;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.longPrefix(arr);

    return 0;
}