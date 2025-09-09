// pre order Traversal of a tree;
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void iterativePreOrder(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s;
    // vector<int> v;
    s.push(root);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        // v.push_back(temp->data);
        cout << temp->data << " ";
        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
    // for (auto i : v)
    //     cout << i << " ";
    // cout << endl;
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void morrisTraversal(node *root)
{
    node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            node *pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = current;
                cout << current->data << " ";
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                current = current->right;
            }
        }
    }
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(6);
    iterativePreOrder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    // levelorder(root);
    // cout << endl;
    // morrisTraversal(root);
    // cout << endl;
    // cout << height(root);
    return 0;
}