#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    void passcheck(string s)
    {

        bool upper = false;
        bool lower = false;
        bool digit = false;

        for (char c : s)
        {
            if (isupper(c))
            {
                upper = true;
            }
            else if (islower(c))
            {
                lower = true;
            }
            else if (isdigit(c))
            {
                digit = true;
            }
        }
        if (upper && lower && digit)
        {
            cout << "STRONG" << endl;
        }
        else
        {
            cout << "WEAK" << endl;
        }
    }
};

int main()
{
    string s;
    getline(cin, s);
    Solution obj;
    obj.passcheck(s);
    return 0;
}