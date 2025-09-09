/*	Saksham is on the Code */
/* Description of the code */
// 'Q1.cpp'

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        left = NULL;
        right = NULL;
    }
    TreeNode(int x) : left(NULL), right(NULL)
    {
        this->val = x;
    }
    void inorder(TreeNode *Node)
    {
        if (Node == NULL)
            return;
        inorder(Node->left);
        cout << Node->val << " ";
        inorder(Node->right);
    }
    void preorder(TreeNode *Node)
    {
        if (Node == NULL)
            return;
        cout << Node->val << " ";
        preorder(Node->left);
        preorder(Node->right);
    }
    void postorder(TreeNode *Node)
    {
        if (Node == NULL)
            return;
        postorder(Node->left);
        postorder(Node->right);
        cout << Node->val << " ";
    }
    void LevelOrder(TreeNode *Node)
    {
        if (Node == NULL)
            return;
        queue<TreeNode *> q;
        q.push(Node);
        while (!q.empty())
        {
            Node = q.front();
            q.pop();
            cout << Node->val << " ";
            if (Node->left != NULL)
                q.push(Node->left);
            if (Node->right != NULL)
                q.push(Node->right);
        }
    }
    void iterativePreorder(TreeNode *Node)
    {
        if (Node == NULL)
            return;
        vector<int> v;
        stack<TreeNode *> st;
        st.push(Node);
        while (!st.empty())
        {
            Node = st.top();
            st.pop();
            v.push_back(Node->val);
            if (Node->right != NULL)
                st.push(Node->right);
            if (Node->left != NULL)
                st.push(Node->left);
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    void iterativeInorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                v.push_back(node->val);
                node = node->right;
            }
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    void iterativePostorder(TreeNode *root)
    {
        vector<int> s;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            s.push_back(root->val);
            if (root->left != NULL)
                st.push(root->left);
            if (root->right != NULL)
                st.push(root->right);
        }
        while (!s.empty())
        {
            cout << s.back() << " ";
            s.pop_back();
        }
        cout << endl;
    }
};

void Solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->inorder(root);
    cout << endl;
    root->iterativePostorder(root);
    // root->preorder(root);
    // cout << endl;
    // root->postorder(root);
    // cout << endl;
};

// Main Function / Driver Code
int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    Solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}