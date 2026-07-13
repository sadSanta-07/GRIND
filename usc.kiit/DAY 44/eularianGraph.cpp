#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis);
    }
}

int main()
{
    int P;
    cin >> P;

    unordered_map<string, int> id;
    vector<pair<int, int>> edges;

    for (int i = 0; i < P; i++)
    {
        string s, t;
        cin >> s >> t;

        if (!id.count(s))
            id[s] = id.size();

        if (!id.count(t))
            id[t] = id.size();

        edges.push_back({id[s], id[t]});
    }

    int n = id.size();

    vector<int> indegree(n, 0), outdegree(n, 0);
    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        outdegree[u]++;
        indegree[v]++;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = outdegree[i] - indegree[i];

        if (diff == 1)
            start++;
        else if (diff == -1)
            end++;
        else if (diff != 0)
        {
            cout << "ASSEMBLY IMPOSSIBLE";
            return 0;
        }
    }

    if (!((start == 1 && end == 1) || (start == 0 && end == 0)))
    {
        cout << "ASSEMBLY IMPOSSIBLE";
        return 0;
    }

    int src = -1;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] + outdegree[i] > 0)
        {
            src = i;
            break;
        }
    }

    if (src == -1)
    {
        cout << "ASSEMBLY POSSIBLE";
        return 0;
    }

    vector<bool> vis(n, false);

    dfs(src, adj, vis);

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] + outdegree[i] > 0 && !vis[i])
        {
            cout << "ASSEMBLY IMPOSSIBLE";
            return 0;
        }
    }

    cout << "ASSEMBLY POSSIBLE";
}