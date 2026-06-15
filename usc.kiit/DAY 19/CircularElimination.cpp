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
    Node *tail;

public:
    Solution()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
            return;
        }

        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    int dltkth(int kth)
    {
        if (head == NULL || kth <= 0)
            return -1;

        Node *curr = head;
        Node *prev = tail;

        while (curr != curr->next)
        {
            for (int i = 1; i < kth; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;

            if (curr == head)
                head = curr->next;

            if (curr == tail)
                tail = prev;

            Node *temp = curr;
            curr = curr->next;

            delete temp;
        }

        return curr->data;
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
    int kth;
    cin >> kth;
    cout << s.dltkth(kth) << endl;

    return 0;
}