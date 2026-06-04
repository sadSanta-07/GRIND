#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j].second > arr[j + 1].second) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i].first << " "
             << arr[i].second << endl;
    }
    return 0;
}