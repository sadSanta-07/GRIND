#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int K, Q;
    cin >> K >> Q;

    vector<int> q(K);

    int front = -1;
    int rear = -1;

    while(Q--)
    {
        string op;
        cin >> op;

        if(op == "ENQUEUE")
        {
            int x;
            cin >> x;

            if((front == rear + 1) ||
               (front == 0 && rear == K - 1))
            {
                cout << "FULL";
            }
            else
            {
                if(front == -1)
                    front = 0;

                rear = (rear + 1) % K;
                q[rear] = x;
            }
        }

        else if(op == "DEQUEUE")
        {
            if(front == -1)
            {
                cout << "EMPTY\n";
            }
            else if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % K;
            }
        }

        else if(op == "FRONT")
        {
            if(front == -1)
                cout << -1 ;
            else
                cout << q[front] ;
        }
    }

    return 0;
}