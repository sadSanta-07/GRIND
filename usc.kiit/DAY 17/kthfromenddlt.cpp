#include <iostream>
#include <vector>
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

    void kthdelfromend(int k){
        if (head == NULL)
            return;

        Node *left = head;
        Node *right = head;

        for (int i = 0; i < k; i++){
            if (left == NULL)
                return;

            left = left->next;
        }

        if (left == NULL){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        while (left->next != NULL){
            left = left->next;
            right = right->next;
        }

        Node *temp = right->next;
        right->next = temp->next;
        delete temp;
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
    cout << "tell the kth position" << endl;
    cin >> k;
    s.kthdelfromend(k);
    s.print();

    return 0;
}