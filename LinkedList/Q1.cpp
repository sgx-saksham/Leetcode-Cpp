#include <bits/stdc++.h>
using namespace std;

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
                p = p->next;
            p->next = new LinkedList(data);
        }
        return head;
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
    LinkedList *mergeTwoLists(LinkedList *list1, LinkedList *list2, LinkedList *i)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        LinkedList *ptr = list1;
        if (list1->data > list2->data)
        {
            ptr = list2;
            list2 = list2->next;
        }
        else
        {
            list1 = list1->next;
        }
        LinkedList *curr = ptr;

        // till one of the list doesn't reaches NULL
        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (!list1)
            curr->next = list2;
        else
            curr->next = list1;

        return ptr;
    }
};

void Merger(LinkedList *v, LinkedList *w, LinkedList *l)
{
    LinkedList *p = v, *q = w, *i = l;
    if (p->next == NULL)
    {
        while (q != NULL)
        {
            i->Push(i, q->data);
            q = q->next;
        }
    }
    if (q->next == NULL)
    {
        while (p != NULL)
        {
            i->Push(i, p->data);
            p = p->next;
        }
    }

    if (p->data < q->data)
    {
        i->Push(i, p->data);
        p = p->next;
        Merger(p, q, i);
    }
    else
    {
        i->Push(i, q->data);
        q = q->next;
        Merger(p, q, i);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n, m, t;
    cin >> n >> m;
    LinkedList *head = NULL, *head2 = NULL, *i = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        head = head->Push(head, t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        head2 = head2->Push(head2, t);
    }
    // Merger(head, head2, i);
    i->mergeTwoLists(head, head2, i);
    i->Print(head);
}