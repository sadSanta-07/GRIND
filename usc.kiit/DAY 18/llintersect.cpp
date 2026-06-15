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

    Node *insert(Node *head, int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
            return newNode;

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        return head;
    }

    void intersect(Node *head1, Node *head2, int X)
    {
        if (X == -1)
            return;

        Node *target = head1;

        while (target != NULL)
        {
            if (target->data == X)
                break;

            target = target->next;
        }

        if (target == NULL)
            return;

        Node *temp = head2;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = target;
    }

    void findIntersection(Node *head1, Node *head2)
    {
        Node *p1 = head1;
        Node *p2 = head2;

        while (p1 != p2)
        {
            if (p1 == NULL)
                p1 = head2;
            else
                p1 = p1->next;

            if (p2 == NULL)
                p2 = head1;
            else
                p2 = p2->next;
        }

        if (p1 == NULL)
            cout << -1 << endl;
        else
            cout << p1->data << endl;
    }
};

int main()
{
    Solution s;

    Node *head1 = NULL;
    Node *head2 = NULL;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        head1 = s.insert(head1, x);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        head2 = s.insert(head2, x);
    }

    int X;
    cin >> X;

    s.intersect(head1, head2, X);

    s.findIntersection(head1, head2);

    return 0;
}