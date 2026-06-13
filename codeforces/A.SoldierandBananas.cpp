// 546A
#include <iostream>
using namespace std;

int soldierNDbanana(int k, int n, int w)
{
    int total_cost = k * w * (w + 1) / 2;
    if (total_cost <= n)
        return 0;
    return total_cost - n;
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    int w;
    cin >> w;

    int res = soldierNDbanana(k, n, w);

    cout << res << endl;

    return 0;
}