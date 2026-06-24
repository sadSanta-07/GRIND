#include <iostream>
using namespace std;

int moves = 0;

void hanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move plate 1 from " << source << " to " << destination << endl;
        moves++;
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);
    cout << "Move plate " << n << " from " << source << " to " << destination << endl;
    moves++;
    hanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    cout << "Total Moves = "
         << moves;

    return 0;
}