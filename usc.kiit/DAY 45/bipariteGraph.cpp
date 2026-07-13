#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int color[100001];
bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : graph[node])
        {
            if (color[next] == 0)
            {
                color[next] = (color[node] == 1) ? 2 : 1;
                q.push(next);
            }
            else if (color[next] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        if (color[i] == 0)
        {
            if (!bfs(i))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";

    for (int i = 1; i <= N; i++)
    {
        cout << color[i] << " ";
    }
    return 0;
}