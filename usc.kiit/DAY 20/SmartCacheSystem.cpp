#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int value;

    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    Node *head;
    Node *tail;

public:
    void insert(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    LRUCache()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void print()
{
    Node* temp = head->next;

    while(temp != tail)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }

    cout << endl;
}


};
int main()
{
    LRUCache cache;

    Node* a = new Node(1, 10);
    Node* b = new Node(2, 20);
    Node* c = new Node(3, 30);

    cache.insert(a);
    cache.insert(b);
    cache.insert(c);

    cache.print();

    return 0;
}