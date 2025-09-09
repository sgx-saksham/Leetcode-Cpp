/*
Q13 - Design Tree Set
first line : N number of elements to be added
second line: N elements
third Line : X number of elements to be deleted
fourth line: X elements

8
5 2 4 3 1 5 3 6
3
4 6 9
*/

#include <bits/stdc++.h>
using namespace std;

class Set
{
public:
    int64_t x = 0;
    void PrintSet()
    {
        int64_t t = x, c = 0;
        while (t != 0)
        {
            c++;
            if (t & 1 == 1)
                cout << c << " ";
            t >>= 1;
        }
        cout << endl;
    }
    void AddElement(int n)
    {
        n--;
        int64_t mask = (1LL << n);
        x |= mask;
    }
    void RemoveElement(int n)
    {
        n--;
        int64_t mask = ~(1LL << n);
        x &= mask;
    }
};

void DesignSet(vector<int> v, vector<int> d)
{
    Set s;
    for (int i = 0; i < v.size(); i++)
        s.AddElement(v[i]);
    s.PrintSet();
    for (int i = 0; i < d.size(); i++)
        s.RemoveElement(d[i]);
    s.PrintSet();
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0 && x < 64)
            v.push_back(x);
    }
    cin >> x;
    vector<int> d(x);
    for (int i = 0; i < x; i++)
        cin >> d[i];
    DesignSet(v, d);
}