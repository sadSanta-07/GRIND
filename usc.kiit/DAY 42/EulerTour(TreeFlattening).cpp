#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 200005;

vector<int> adj[MAX];
ll val[MAX], flat[MAX];
int tin[MAX], tout[MAX];
ll seg[4 * MAX];

int timer = 0;

void dfs(int node, int parent)
{
    tin[node] = ++timer;
    flat[timer] = val[node];

    for (int child : adj[node])
    {
        if (child != parent)
            dfs(child, node);
    }

    tout[node] = timer;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = flat[l];
        return;
    }

    int mid = (l + r) / 2;

    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void update(int idx, int l, int r, int pos, ll value)
{
    if (l == r)
    {
        seg[idx] = value;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(idx * 2, l, mid, pos, value);
    else
        update(idx * 2 + 1, mid + 1, r, pos, value);

    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

ll query(int idx, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return 0;

    if (ql <= l && r <= qr)
        return seg[idx];

    int mid = (l + r) / 2;

    return query(idx * 2, l, mid, ql, qr) +
           query(idx * 2 + 1, mid + 1, r, ql, qr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    build(1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            ll v;
            cin >> x >> v;

            update(1, 1, n, tin[x], v);
        }
        else
        {
            int x;
            cin >> x;

            cout << query(1, 1, n, tin[x], tout[x]) << "\n";
        }
    }

    return 0;
}