

bool idxmap(const vector<vector<int>> &arr, int n, int m, int x)
{
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if (arr[row][col] == x)
            return true;

        if (arr[row][col] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x;
    cin >> x;
    cout << idxmap(arr, n, m, x);
    return 0;
}