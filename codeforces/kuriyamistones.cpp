#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v(n + 1);
    vector<long long> u(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        u[i] = v[i];
    }

    sort(u.begin() + 1, u.end());

    vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref1[i] = pref1[i - 1] + v[i];
        pref2[i] = pref2[i - 1] + u[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1)
            cout << pref1[r] - pref1[l - 1] << '\n';
        else
            cout << pref2[r] - pref2[l - 1] << '\n';
    }

    return 0;
}