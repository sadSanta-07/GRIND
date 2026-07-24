// 1904A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int xK, yK;
        cin >> xK >> yK;

        int xQ, yQ;
        cin >> xQ >> yQ;

        vector<pair<int,int>> k, q;

        int dx[] = {a, a, -a, -a, b, b, -b, -b};
        int dy[] = {b, -b, b, -b, a, -a, a, -a};

        for (int i = 0; i < 8; i++) {
            k.push_back({xK + dx[i], yK + dy[i]});
            q.push_back({xQ + dx[i], yQ + dy[i]});
        }

        int ans = 0;

        for (int i = 0; i < k.size(); i++) {
            for (int j = 0; j < q.size(); j++) {
                if (k[i].first == q[j].first && k[i].second == q[j].second) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}