#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minMaxQuery(vector<int> &arr, int N, int l, int u)
    {
        int K = log2(N) + 1;
        vector<vector<int>> stMin(N, vector<int>(K));
        vector<vector<int>> stMax(N, vector<int>(K));

        for (int i = l; i <= u; i++)
        {
            arrmin = min(arrmin, arr[i]);
            arrmax = max(arrmax, arr[i]);
        }
        return arrmax - arrmin;
    }
};

int main()
{
    Solution obj;
    int N, l, u;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int query;
    cout << "no: of queries" << endl;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        cin >> l >> u;
        cout << obj.minMaxQuery(arr, N, l, u) << endl;
    }

    return 0;
}