#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

const ll NEG = -4e18;

struct Edge
{
    int u, v;
    ll w;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<int>> rev(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        rev[v].push_back(u);
    }
    vector<int> canReachEnd(n + 1, false);
    queue<int> q;
    q.push(n);
    canReachEnd[n] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : rev[cur])
        {
            if (!canReachEnd[nxt])
            {
                canReachEnd[nxt] = true;
                q.push(nxt);
            }
        }
    }
    vector<ll> profit(n + 1, NEG);
    profit[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            if (profit[e.u] == NEG)
                continue;

            if (profit[e.u] + e.w > profit[e.v])
            {
                profit[e.v] = profit[e.u] + e.w;
            }
        }
    }
    for (auto e : edges)
    {
        if (profit[e.u] == NEG)
            continue;
        if (profit[e.u] + e.w > profit[e.v] && canReachEnd[e.v])
        {
            cout << "INFINITE PROFIT";
            return 0;
        }
    }

    if (profit[n] == NEG)
        cout << "UNREACHABLE";
    else
        cout << profit[n];

    return 0;
}