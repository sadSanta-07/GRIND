#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;

    Node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node *crtlist(vector<int> &arr)
{
    Node *head = NULL;
    Node *tmp = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        if (head == NULL)
        {
            head = tmp = new Node(arr[i]);
        }
        else
        {
            tmp->next = new Node(arr[i]);
            tmp = tmp->next;
        }
    }

    return head;
}

Node *merge(Node *a, Node *b)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    if (a != NULL)
        tail->next = a;

    if (b != NULL)
        tail->next = b;

    return dummy->next;
}

Node *flatten(vector<Node *> &lists)
{
    if (lists.empty())
        return NULL;

    Node *result = lists[0];

    for (int i = 1; i < lists.size(); i++)
    {
        result = merge(result, lists[i]);
    }

    return result;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<Node *> lists;

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);

        vector<int> arr;
        int x;

        while (ss >> x)
        {
            arr.push_back(x);
        }

        Node *head = crtlist(arr);
        lists.push_back(head);
    }

    Node *result = flatten(lists);

    printList(result);

    return 0;
}