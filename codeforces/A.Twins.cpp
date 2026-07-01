//160A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int mySum = 0;
    int count = 0;

    for (int coin : a) {
        mySum += coin;
        count++;

        if (mySum > total - mySum) {
            cout << count;
            break;
        }
    }

    return 0;
}