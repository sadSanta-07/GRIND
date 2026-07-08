#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<ll> treasure;
ll ans = 0;

void dfs(int node, int parent, int level)
{
    if(level % 2 == 0)
        ans += treasure[node];

    for(int child : adj[node])
    {
        if(child == parent)
            continue;

        dfs(child, node, level + 1);
    }
}

int main()
{
    int N;
    cin >> N;

    treasure.resize(N + 1);
    adj.resize(N + 1);

    for(int i = 1; i <= N; i++)
        cin >> treasure[i];

    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << ans;
}