#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    Node *head;

public:
    Solution(){
        head = NULL;
    }
    void insert(int val){
        Node *newNode = new Node(val);

        if (head == NULL){
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
    void reverse(){
        Node *prev = NULL;
        Node *curr = head;

        while (curr){
            Node *next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
    void print(){
        Node *temp = head;

        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        s.insert(x);
    }
    s.reverse();
    s.print();

    return 0;
}