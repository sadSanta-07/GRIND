#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longseq(vector<int> &arr)
{
    unordered_set<int> ust(arr.begin(), arr.end());
    int longest = 0;
    for (int num : ust)
    {
        if (ust.find(num - 1) == ust.end())
        {
            int curr = num;
            int len = 1;
            while (ust.find(curr + 1) != ust.end())
            {
                curr++;
                len++;
            }
            longest = max(longest, len);
        }
    }
    return longest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longseq(arr);

    return 0;
}