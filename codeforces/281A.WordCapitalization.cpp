// 281A

#include <iostream>

using namespace std;

class Solution
{
public:
    string WordCapitalization(string s)
    {
        if (islower(s[0]))
        {
            s[0] = toupper(s[0]);
        }
        return s;
    }
};

int main()
{
    Solution obj;
    string s;
    cin >> s;

    cout << obj.WordCapitalization(s);

    return 0;
}