// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };

// Node *createNode(int data)
// {
//     Node *newNode = new Node();
//     newNode->data = data;
//     newNode->left = newNode->right = nullptr;
//     return newNode;
// }
// Node *first = nullptr;
// Node *second = nullptr;
// Node *prevNode = nullptr;

// Node *insertNode(Node *root, int data)
// {
//     if (root == nullptr)
//     {
//         return createNode(data);
//     }
//     if (data < root->data)
//         if (data < root->data)
//         {
//             root->left = insertNode(root->left, data);
//         }
//         else if (data > root->data)
//         {
//             root->right = insertNode(root->right, data);
//         }

//     return root;
// }

// void inorderTraversal(Node *root)
// {
//     if (root != nullptr)
//     {
//         inorderTraversal(root->left);
//         if (prevNode != nullptr && prevNode->data > root->data)
//         {
//             if (first == nullptr)
//                 first = prevNode;
//             second = root;
//         }
//         prevNode = root;
//         inorderTraversal(root->right);
//     }
// }

// void recoverBST(Node *root)
// {
//     first = second = prevNode = nullptr;

//     inorderTraversal(root);

//     if (first && second)
//         swap(first->data, second->data);
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *first = nullptr;
Node *second = nullptr;
Node *prevNode = nullptr;

Node *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);

    if (prevNode != nullptr && prevNode->data > root->data)
    {
        if (first == nullptr)
            first = prevNode;

        second = root;
    }

    prevNode = root;

    inorderTraversal(root->right);
}

void recoverBST(Node *root)
{
    first = second = prevNode = nullptr;

    inorderTraversal(root);

    if (first && second)
        swap(first->data, second->data);
}

void printLevelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = buildTree(arr);

    recoverBST(root);

    printLevelOrder(root);

    return 0;
}