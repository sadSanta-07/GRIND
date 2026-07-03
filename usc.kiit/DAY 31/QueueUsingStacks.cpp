#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue()
    {
        if (s1.empty())
        {
            return;
        }

        s1.pop();
    }

    int front()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }

    int size()
    {
        return s1.size();
    }
};

int main()
{
    queue q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s;

        if (s == "ADD")
        {
            cin >> x;
            q.enqueue(x);
        }
        else if (s == "NEXT")
        {
            cout << q.front() << endl;
            q.dequeue();
        }
        else
        {
            cout << "INVALID SHII";
        }
    }
}