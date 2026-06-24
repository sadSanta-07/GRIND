#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node* cloneList(Node* head)
    {
        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Create clone nodes
        while(curr)
        {
            mp[curr] = new Node(curr->data);
            curr = curr->next;
        }

        curr = head;

        // Connect next and random pointers
        while(curr)
        {
            mp[curr]->next =
                curr->next ? mp[curr->next] : NULL;

            mp[curr]->random =
                curr->random ? mp[curr->random] : NULL;

            curr = curr->next;
        }

        return mp[head];
    }
};

int main()
{
    int n;
    cin >> n;

    if(n == 0)
        return 0;

    vector<Node*> nodes(n);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        nodes[i] = new Node(x);
    }

    for(int i = 0; i < n - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
    }


    vector<int> randomIndex(n);

    for(int i = 0; i < n; i++)
    {
        cin >> randomIndex[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(randomIndex[i] != -1)
        {
            nodes[i]->random =
                nodes[randomIndex[i]];
        }
    }

    Node* head = nodes[0];

    Solution s;

    Node* clonedHead = s.cloneList(head);

    unordered_map<Node*, int> indexMap;

    Node* curr = clonedHead;
    int idx = 0;

    while(curr)
    {
        indexMap[curr] = idx;
        idx++;
        curr = curr->next;
    }

    curr = clonedHead;

    while(curr)
    {
        cout << curr->data << " ";

        if(curr->random)
            cout << indexMap[curr->random];
        else
            cout << -1;

        cout << "\n";

        curr = curr->next;
    }

    return 0;
}