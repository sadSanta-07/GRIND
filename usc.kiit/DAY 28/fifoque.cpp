#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int x;
        if (q.empty() && (s == "WITHDRAW" || s == "NEXT"))
        {
            cout << -1 << endl;
        }
        else if (s == "REGISTER")
        {
            cin >> x;
            q.push(x);
        }
        else if (s == "WITHDRAW")
        {
            q.pop();
        }
        else if (s == "NEXT")
        {
            cout << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}