#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge
{
    int to;
    ll travel;
    ll expiry;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll t, e;

        cin >> u >> v >> t >> e;

        adj[u].push_back({v, t, e});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        ll time = current.first;
        int node = current.second;
        if (time != dist[node])
            continue;

        for (auto edge : adj[node])
        {
            if (time >= edge.expiry)
                continue;

            ll newTime = time + edge.travel;
            if (newTime < dist[edge.to])
            {
                dist[edge.to] = newTime;
                pq.push({newTime, edge.to});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == LLONG_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}