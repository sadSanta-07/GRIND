// 151A
#include <iostream>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int overall_drink = k * l;
    int drinkToasts = overall_drink / nl;
    int limeForToast = c * d;
    int saltForToast = p / np;
    int mn = min(drinkToasts, min(limeForToast, saltForToast));
    int ans = mn / n;
    cout << ans;

    return 0;
}