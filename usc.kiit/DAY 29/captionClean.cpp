#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;

    int num = 0;
    char op = '+';

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (st.empty())
        {
            st.push(ch);
        }
        else if (!st.empty() && st.top() == ch)
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }

    string ans;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    if (ans.empty())
    {
        cout << "EMPTY";
    }
    else
    {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }

    return 0;
}