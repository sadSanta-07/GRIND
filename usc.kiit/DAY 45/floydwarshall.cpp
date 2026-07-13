#include <iostream>
using namespace std;

const long long INF = 1e18;
const int MAX = 205;

long long dist[MAX][MAX];
int N, M;

void initialize()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void inputGraph()
{
    cin >> N >> M;

    initialize();

    for (int i = 0; i < M; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        if (w < dist[u][v])
            dist[u][v] = w;
    }
}

void floydWarshall()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {

                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void answerQueries()
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }
}

int main()
{
    inputGraph();
    floydWarshall();
    answerQueries();
    return 0;
}