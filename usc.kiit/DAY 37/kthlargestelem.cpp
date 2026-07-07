#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void kthLrg(vector<int> &arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr)
    {
        if (pq.size() < k)
        {
            pq.push(x);
        }
        else if (pq.top() < x)
        {
            pq.pop();
            pq.push(x);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    kthLrg(arr, n, k);

    return 0;
}