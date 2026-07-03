#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> st;
    stack<int> minSt;

    int q;
    cin >> q;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "PUSH")
        {
            int x;
            cin >> x;

            st.push(x);

            if (minSt.empty())
                minSt.push(x);
            else
                minSt.push(min(x, minSt.top()));
        }
        else if (op == "POP")
        {
            if (!st.empty())
            {
                st.pop();
                minSt.pop();
            }
        }
        else if (op == "MIN")
        {
            if (st.empty())
                cout << -1 << endl;
            else
                cout << minSt.top() << endl;
        }
    }

    return 0;
}