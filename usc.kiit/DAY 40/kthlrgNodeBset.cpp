#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int x)
{
    if (root == nullptr)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int cnt = 0;
int ans = 0;

void reverseInorder(Node *root, int k)
{
    if (root == nullptr || cnt >= k)
        return;

    reverseInorder(root->right, k);

    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }

    reverseInorder(root->left, k);
}

int main()
{
    int n;
    cin >> n;

    Node *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int k;
    cin >> k;

    reverseInorder(root, k);

    cout << ans;
}