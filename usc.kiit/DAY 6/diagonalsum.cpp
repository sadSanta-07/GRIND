#include <iostream>
using namespace std;

void diagsum(int arr[][50], int n)
{
    int diagsum1 = 0;
    int diagsum2 = 0;

    for (int i = 0; i < n; i++)
    {
        diagsum1 += arr[i][i];

        diagsum2 += arr[i][n - 1 - i];
    }

    if (diagsum1 == diagsum2)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    diagsum(arr, n);

    return 0;
}