#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word,
         int row, int col, int index)
{
    if (index == word.length())
        return true;

    if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size() ||
        board[row][col] != word[index])
    {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '#';

    bool found =
        dfs(board, word, row - 1, col, index + 1) ||
        dfs(board, word, row + 1, col, index + 1) ||
        dfs(board, word, row, col - 1, index + 1) ||
        dfs(board, word, row, col + 1, index + 1);

    board[row][col] = temp;

    return found;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(board, word, i, j, 0))
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}