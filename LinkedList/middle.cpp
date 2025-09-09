/*
    SGX is on the Code
*/
// 'middle.cpp'
/*
Test Cases for the code
*/

#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

void PrintList(list<int> l)
{
    for (auto &&i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

class LinkedList
{
public:
    int data;
    LinkedList *Next;
    LinkedList()
    {
        this->Next = NULL;
    }
    LinkedList(int data)
    {
        this->data = data;
        this->Next = NULL;
    }
    LinkedList *Add(int data, LinkedList *head)
    {
        if (head == NULL)
        {
            LinkedList *temp = new LinkedList(data);
            head = temp;
        }
        else
        {
            LinkedList *temp = head;
            while (temp->Next != NULL)
                temp = temp->Next;
            temp->Next = new LinkedList(data);
        }
        return head;
    }
    void Print(LinkedList *head)
    {
        LinkedList *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
    int Mid_element(LinkedList *head)
    {
        LinkedList *sp = head, *fp = head;
        while (fp != NULL && fp->Next != NULL)
        {
            sp = sp->Next;
            fp = fp->Next->Next;
        }
        return sp->data;
    }
    LinkedList *Delete_Mid(LinkedList *head)
    {
        LinkedList *sp = head, *fp = head, *pre = sp;
        while (fp != NULL && fp->Next != NULL)
        {
            pre = sp;
            sp = sp->Next;
            fp = fp->Next->Next;
        }
        pre->Next = sp->Next;
        delete sp;
        return head;
    }
    LinkedList *Delete_Element(LinkedList *head, int target)
    {
        LinkedList *p = head, *i = p;
        while (p != NULL)
        {
            i = p;
            p = p->Next;
            if (p->data == target)
            {
                break;
            }
        }
        i->Next = p->Next;
        delete p;
        return head;
    }
    LinkedList *Insert_element(LinkedList *head, int pos, int data)
    {
        if (Size_of_LL(head) + 1 < pos)
            return head;
        LinkedList *p = head, *ip = p;
        for (int i = 0; i < pos - 1; i++)
            p = p->Next;
        ip = p->Next;
        p->Next = new LinkedList(data);
        p->Next->Next = ip;
        return head;
    }
    int Size_of_LL(LinkedList *head)
    {
        LinkedList *p = head;
        int c = 0;
        while (p != NULL)
        {
            c++;
            p = p->Next;
        }
        return c;
    }
};

// Solving functions
void Solve()
{
    int n, t;
    cin >> n;
    list<int> l;
    LinkedList *h = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        h = h->Add(t, h);
        l.push_back(t);
    }
    // int d = h->Mid_element(h);
    // h = h->Delete_Mid(h);
    // h->Delete_Element(h, 2);
    // int s = h->Size_of_LL(h);

    h->Insert_element(h, 3, 3);
    h->Print(h);
    // cout << d << endl;
    PrintList(l);
    initializer_list<int> m = {-1, -2, -3};

    l.insert(l.begin(), m);
    PrintList(l);
    // for (auto it = m.begin(); it != m.end(); ++it)
    // {
    //     cout << it << " ";
    // }
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

    long t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}