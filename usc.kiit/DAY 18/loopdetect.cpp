#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
    Node *head;

public:
    Solution()
    {
        head = NULL;
    }
    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    

    void pos(int pos)
    {
        if (pos == -1)
        {
            return;
        }

        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        Node *target = head;

        for (int i = 0; i < pos; i++)
        {
            target = target->next;
        }
        last->next = target;
    }


    void loopcheck()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << "YES" << endl;
                return;
            }
        }

        cout << "NO" << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        s.insert(x);
    }
    int pos;
    cin >> pos;
    s.pos(pos);
    s.loopcheck();

    return 0;
}