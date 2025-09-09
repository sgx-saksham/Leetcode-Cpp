/*
    SGX is on the Code
*/
// 'creation.cpp'
/*
Test Cases for the code
*/

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
    LinkedList *Push(LinkedList *head, int data)
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
            {
                p = p->next;
            }
            p->next = new LinkedList(data);
        }
        return head;
    }
    LinkedList *InsertElement(LinkedList *head, int pos, int data)
    {
        if (Size(head) + 1 < pos)
            return head;
        LinkedList *p = head, *ip = p;
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        ip = p->next;
        p->next = new LinkedList(data);
        p->next->next = ip;
        return head;
    }
    LinkedList *Delete_Element_byData(LinkedList *head, int target)
    {
        LinkedList *p = head, *ip = p;
        bool flag = false;
        while (p->next != NULL)
        {
            ip = p;
            p = p->next;
            if (p->data == target)
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            ip->next = p->next;
            delete p;
        }
        return head;
    }
    int Size(LinkedList *head)
    {
        LinkedList *p = head;
        int c = 0;
        while (p != NULL)
        {
            c++;
            p = p->next;
        }
        return c;
    }
    void Print(LinkedList *head)
    {
        if (head == NULL)
            cout << "Empty\n";
        else
        {
            LinkedList *p = head;
            while (p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
    int Mid_Element(LinkedList *head)
    {
        LinkedList *sp = head, *fp = head;
        while (fp != NULL && fp->next != NULL)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp->data;
    }
    LinkedList *Delete_Mid_Element(LinkedList *head)
    {
        LinkedList *sp = head, *fp = head, *pre = sp;
        while (fp != NULL && fp->next != NULL)
        {
            pre = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        pre->next = sp->next;
        delete sp;
        return head;
    }
    LinkedList *Delete_LinkedList(LinkedList *head)
    {
        auto pre = head;
        head = head->next;
        while (head != NULL)
        {
            delete pre;
            pre = head;
            head = head->next;
        }
    }
    void Print_Rev(LinkedList *head)
    {
        if (head == NULL)
            return;
        Print_Rev(head->next);
        cout << head->data << " ";
    }
    LinkedList *Reverse(LinkedList *head)
    {
        LinkedList *c = head, *n = head, *p = NULL;
        while (c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};

// Solving functions
void Solve()
{
    int n, t;
    cin >> n;
    LinkedList *head = NULL, *head2 = NULL;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v[i] = t;
        head = head->Push(head, t);
    }
    head->Print(head);
    head = head->Delete_Element_byData(head, 4);
    head->Print(head);
    head = head->InsertElement(head, 5, 5);
    head->Print(head);
    head = head->Delete_Mid_Element(head);
    head->Print(head);
    head = head->Delete_Mid_Element(head);
    head->Print(head);
    head = head->Delete_LinkedList(head);
    head->Print(head);
    for (int i = 0; i < n; i++)
    {
        head = head->Push(head, v[i]);
    }
    head = head->Delete_Element_byData(head, 4);
    head = head->InsertElement(head, 5, 5);
    head->Print_Rev(head);
    cout << endl;
    head->Print(head);
    head2 = head->Reverse(head);
    head2->Print(head2);
    head2->Print_Rev(head2);
    cout << endl;
};

// void cream()
// {
//     while (n--)
//     {
//         cin >> t;
//         LinkedList *one = NULL;
//         one = new LinkedList();
//         one->data = t;
//     }
//     LinkedList *head;
//     LinkedList *one = NULL;
//     LinkedList *two = NULL;
//     one = new LinkedList();
//     two = new LinkedList();
//     one->data = 1;
//     two->data = 2;
//     one->Next = two;
//     two->Next = NULL;
//     head = one;
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->Next;
//     }
// }

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