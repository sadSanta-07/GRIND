#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(vector<int> &arr)
{
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        // Left Child
        if (i < arr.size() && arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right Child
        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}

void leftBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{
    vector<int> temp;

    Node *curr = root->right;

    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    if (!isLeaf(root))
        ans.push_back(root->data);

    leftBoundary(root, ans);

    addLeaves(root, ans);

    rightBoundary(root, ans);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = insert(arr);

    vector<int> ans = boundary(root);

    for (int x : ans)
    {
        cout << x << " ";
    }
}