#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long rangescore(vector<int> &arr, int L, int R)
    {
        unordered_map<int, int> freq;

        for (int i = L; i <= R; i++)
        {
            freq[arr[i]]++;
        }

        long long score = 0;

        for (auto &p : freq)
        {
            score += 1LL * p.second * p.second;
        }

        return score;
    }
};

int main()
{
    int N, L, R;
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
        cout << "lower range" << endl;
        cin >> L;
        cout << "upper range" << endl;
        cin >> R;
    }

    Solution obj;

    for (int i = 0; i < query; i++)
    {
        cin >> L >> R;

        cout << obj.rangescore(arr, L, R) << endl;
    }

    return 0;
}