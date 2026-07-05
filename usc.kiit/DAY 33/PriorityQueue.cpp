#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<pair<int, int>> pq;
    vector<long long> ids(N);

    for (int i = 0; i < N; i++) {
        long long id;
        int priority;
        cin >> id >> priority;
        ids[i] = id;
        pq.push({priority, -i});
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int arrival = -top.second;
        cout << ids[arrival] << '\n';
    }
    return 0;
}