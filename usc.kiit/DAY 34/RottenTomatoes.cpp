#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    int rottentomato(vector<vector<int>> &arr, int m, int n)
    {
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        // push
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // bfs

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int i = front.first.first;
            int j = front.first.second;
            int time = front.second;
            ans = max(ans, time);

            // top
            if (i - 1 >= 0 && !vis[i - 1][j] && arr[i - 1][j] == 1)
            {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }

            // right
            if (j + 1 < m && !vis[i][j + 1] && arr[i][j + 1] == 1)
            {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }

            // bottom
            if (i + 1 < n && !vis[i + 1][j] && arr[i + 1][j] == 1)
            {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }

            // left
            if (j - 1 >= 0 && !vis[i][j - 1] && arr[i][j - 1] == 1)
            {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }
        // check fresh orange left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solution s;
    cout << s.rottentomato(arr, m, n) << endl;
}
