// .791A
#include <iostream>

using namespace std;

class Solution
{
public:
    int bearbro(int a, int b)
    {
        int year = 0;

        while (a <= b)
        {
            a *= 3;
            b *= 2;
            year++;
        }

        return year;
    }
};

int main()
{
    Solution obj;
    int a;
    cin >> a;
    int b;
    cin >> b;

    cout << obj.bearbro(a, b) << "\n";

    return 0;
}