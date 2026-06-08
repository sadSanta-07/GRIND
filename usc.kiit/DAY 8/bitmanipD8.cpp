#include <iostream>
using namespace std;

class Solution {
public:

    void checkParity(int num) {
        int count = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }
        if (count % 2 == 1) {
            cout << "ANSWER" << endl;
        }
        else {
            cout << "SAFE" << endl;
        }
    }
};

int main() {

    int N;
    cin >> N;

    Solution obj;

    for (int i = 0; i < N; i++) {

        int num;
        cin >> num;

        obj.checkParity(num);
    }

    return 0;
}