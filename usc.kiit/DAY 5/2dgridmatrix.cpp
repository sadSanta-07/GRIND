#include <iostream>
using namespace std;

void processLibrary(int arr[][50], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // Occupied seat
            if(arr[i][j] == 1)
            {
                cout << "O ";
            }

            else
            {
                bool disturbed = false;

                // Top
                if(i > 0 && arr[i-1][j] == 1)
                    disturbed = true;

                // Bottom
                if(i < n-1 && arr[i+1][j] == 1)
                    disturbed = true;

                // Left
                if(j > 0 && arr[i][j-1] == 1)
                    disturbed = true;

                // Right
                if(j < n-1 && arr[i][j+1] == 1)
                    disturbed = true;

                if(disturbed)
                    cout << "X ";
                else
                    cout << "S ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[50][50];

    // Input matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    processLibrary(arr, n);

    return 0;
}