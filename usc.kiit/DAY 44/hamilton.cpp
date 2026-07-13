#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, M;

bool dfs(int node, int count)
{
    if (count == N)
        return true;

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            visited[next] = true;

            if (dfs(next, count + 1))
                return true;

            visited[next] = false;
        }
    }

    return false;
}

int main()
{
    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int start = 1; start <= N; start++)
    {
        visited.assign(N + 1, false);

        visited[start] = true;

        if (dfs(start, 1))
        {
            cout << "MISSION POSSIBLE";
            return 0;
        }
    }

    cout << "MISSION FAILED";
}