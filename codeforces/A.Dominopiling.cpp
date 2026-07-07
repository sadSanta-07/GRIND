// 50A

#include <iostream>
using namespace std;

class Solution
{
public:
    int Dominopiling(int n, int m)
    {
        return (n * m) / 2;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    cout << (n * m) / 2;

    return 0;
}