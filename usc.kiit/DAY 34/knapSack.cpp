#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;

    vector<int> cost(N);
    vector<int> energy(N);

    for(int i = 0; i < N; i++)
    {
        cin >> cost[i] >> energy[i];
    }

    vector<int> dp(X + 1, 0);

    for(int c = 1; c <= X; c++)
    {
        for(int i = 0; i < N; i++)
        {
            if(c >= cost[i])
            {
                dp[c] = max(
                    dp[c],
                    dp[c - cost[i]] + energy[i]
                );
            }
        }
    }

    cout << dp[X] << endl;
}