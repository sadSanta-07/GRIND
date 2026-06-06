#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {

        // LEFT TRIANGLE
        for(int j=1; j<=i; j++) {
            cout << j;
        }

        // MIDDLE @
        for(int j=1; j<=2*(N-i); j++) {
            cout << "@";
        }

        // RIGHT TRIANGLE
        for(int j=i; j>=1; j--) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}