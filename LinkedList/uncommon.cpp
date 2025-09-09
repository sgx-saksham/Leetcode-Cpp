/*
    SGX is on the Code
*/
// 'uncommon.cpp'
/*
Test Cases for the code
*/

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
struct Node
{
    int data;
    struct Node *next;
    void push(struct Node **head_ref, int new_data)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    void traverse(struct Node **head3, struct Node *temp1, struct Node *temp2)
    {
        while (temp1 != NULL)
        {
            int val = temp1->data;
            struct Node *t = temp2;
            int x = 0;
            while (t != NULL)
            {
                if (t->data == val)
                {
                    x = 1;
                    break;
                }
                t = t->next;
            }
            if (x == 0)
            {
                push(head3, temp1->data);
            }
            temp1 = temp1->next;
        }
    }
    struct Node *UncommonNodes(struct Node *list1, struct Node *list2)
    {
        struct Node *head3 = NULL;
        traverse(&head3, list2, list1);
        traverse(&head3, list1, list2);
        return head3;
    }
};
// Solving functions
void Solve()
{
    int n;
    cin >> n;
    Node list1;
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}