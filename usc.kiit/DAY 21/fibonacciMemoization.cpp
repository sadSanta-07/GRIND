#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> dp;
int fun(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp.find(n) != dp.end())
    {
        return dp[n];
    }
    int a1 = fun(n - 1);
    int a2 = fun(n - 2);
    int ans = a1 + a2;
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << fun(n) << endl;
}