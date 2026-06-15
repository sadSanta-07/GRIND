#include <iostream>
#include <cstdint>

using namespace std;

class Node
{
public:
    int data;
    Node* npx;

    Node(int val)
    {
        data = val;
        npx = NULL;
    }
};

Node* XOR(Node* a, Node* b)
{
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

class XORLinkedList
{
private:
    Node* head;

public:
    XORLinkedList()
    {
        head = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        while(true)
        {
            next = XOR(prev, curr->npx);

            if(next == NULL)
                break;

            prev = curr;
            curr = next;
        }
        newNode->npx = curr;

        curr->npx = XOR(prev, newNode);
    }

    void print()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while(curr != NULL)
        {
            cout << curr->data << " ";

            next = XOR(prev, curr->npx);

            prev = curr;
            curr = next;
        }

        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    XORLinkedList list;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list.insert(x);
    }

    list.print();

    return 0;
}