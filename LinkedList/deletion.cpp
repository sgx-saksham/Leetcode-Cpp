/*
    SGX is on the Code
*/
// 'deletion.cpp'
/*
Test Cases for the code
*/

// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

class LinkedList
{
public:
    int data;
    LinkedList *next;
    LinkedList()
    {
        this->next = NULL;
    }
    LinkedList(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    LinkedList *Pushback(LinkedList *head, int data)
    {
        if (head == NULL)
        {
            LinkedList *p = new LinkedList(data);
            head = p;
        }
        else
        {
            LinkedList *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = new LinkedList(data);
        }
        return head;
    }
    int Size(LinkedList *head)
    {
        LinkedList *p = head;
        int c = 0;
        if (head == NULL)
            return c;
        else
        {
            while (p != NULL)
            {
                c++;
                p = p->next;
            }
        }
        return c;
    }
    void Print(LinkedList *head)
    {
        LinkedList *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void Print_Rev(LinkedList *head)
    {
        LinkedList *p = head, *i = head;
        int s = 0;
        vector<int> v;
        while (p != NULL)
        {
            v.push_back(p->data);
            p = p->next;
            s++;
        }
        reverse(v.begin(), v.end());
        for (int i = s - 1; i >= 0; i--)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

// Solving functions
void Solve()
{
    int n, t;
    cin >> n;
    LinkedList *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        head = head->Pushback(head, t);
    }
    head->Print(head);
    int s = head->Size(head);
    cout << s << endl;
    head->Print_Rev(head);
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