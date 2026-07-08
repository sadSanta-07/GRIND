#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    int i = row;
    int j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    i = row;
    j = col;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j++;
    }

    return true;
}

void solve(int row,
           vector<string> &board,
           vector<vector<string>> &ans,
           int n)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';

            solve(row + 1, board, ans, n);

            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));

    vector<vector<string>> ans;

    solve(0, board, ans, n);

    if (ans.empty())
    {
        cout << -1;
        return 0;
    }

    for (auto solution : ans)
    {
        for (auto row : solution)
            cout << row << endl;

        cout << endl;
    }

    return 0;
}