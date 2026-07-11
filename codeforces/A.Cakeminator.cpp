#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> cake(r);

    for (int i = 0; i < r; i++) {
        cin >> cake[i];
    }

    vector<bool> safeRow(r, true);
    vector<bool> safeCol(c, true);

    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cake[i][j] == 'S') {
                safeRow[i] = false;
                break;
            }
        }
    }

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (cake[i][j] == 'S') {
                safeCol[j] = false;
                break;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (safeRow[i] || safeCol[j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}