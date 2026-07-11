#include <iostream>
#include <vector>
using namespace std;

vector<int> zigzag(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> diag(row + col - 1);
    int d;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            d = i + j;
            diag[d].push_back(mat[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < row + col - 1; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = diag[i].size() - 1; j >= 0; j--)
            {
                ans.push_back(diag[i][j]);
            }
        }
        else
        {
            for (int x : diag[i])
            {
                ans.push_back(x);
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = zigzag(mat);
    for (int x : ans)
    {
        cout << x << " ";
    }
}