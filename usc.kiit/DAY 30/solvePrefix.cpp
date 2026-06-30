#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int solveprefix(string prefix)
{
    stack<int> st;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        int c = prefix[i];
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();

            int operand2 = st.top();
            st.pop();

            int result;

            if (c == '+')
                result = operand1 + operand2;
            else if (c == '-')
                result = operand1 - operand2;
            else if (c == '*')
                result = operand1 * operand2;
            else
                result = operand1 / operand2;

            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string prefix = "-*+2345";
    cout << solveprefix(prefix) << endl;
    return 0;
}
