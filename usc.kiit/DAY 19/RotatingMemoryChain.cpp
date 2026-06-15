#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void rotateRight(int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return;

        int n = 1;

        Node *tempTail = head;

        while (tempTail->next)
        {
            tempTail = tempTail->next;
            n++;
        }

        k %= n;

        if (k == 0)
            return;

        tempTail->next = head;
        head->prev = tempTail;

        Node *newTail = head;

        for (int i = 0; i < n - k - 1; i++)
        {
            newTail = newTail->next;
        }

        Node *newHead = newTail->next;

        newTail->next = NULL;
        newHead->prev = NULL;

        head = newHead;
        tail = newTail;
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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

    int k;
    cin >> k;

    s.rotateRight(k);
    s.print();
}