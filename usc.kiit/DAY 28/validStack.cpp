#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int arr[100];

public:
    Stack() { top = -1; }

    bool match(char open, char close)
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '<' && close == '>') ||
               (open == '[' && close == ']');
    }
    char pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    char peek()
    {
        if (top < 0)
            return '\0';

        return arr[top];
    }

    void push(int x)
    {
        if (top >= 99)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " to stack\n";
    }

    bool isEmpty()
    {
        return (top < 0);
    }
};

bool isValid(string s)
{
    Stack st;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[' || ch == '<')
        {
            st.push(ch);
        }
        else
        {
            if (st.isEmpty())
                return false;

            if (st.match(st.peek(), ch))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main()
{
    string s = "{(<[]>)}";

    if (isValid(s))
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}