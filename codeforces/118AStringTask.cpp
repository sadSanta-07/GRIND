#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char stringtask(string s)
    {
        for (char c : s)
        {
            char lower = tolower(c);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u' && lower != 'y'){
                cout<<"."<<lower;
            }
        }
    }
};

int main()
{
    Solution obj;
    string s;
    cin >> s;

    cout << obj.stringtask(s);

    return 0;
}