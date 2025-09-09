#include <bits/stdc++.h>
using namespace std;

class QueueArr
{
public:
    int a[100], t = -1, c = 0;
    void push(int n)
    {
        t++;
        a[t] = n;
    }
    void pop()
    {
        a[c] = 0;
        c++;
    }
    int front()
    {
        if (c > t)
            return -1;
        return a[c];
    }
    void print()
    {
        if (c > t)
        {
            cout << "empty\n";
            return;
        }
        for (int i = c; i <= t; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    QueueArr a;
    vector<vector<string>> vi;
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string l;
        vector<string> v;
        while (ss >> l)
            v.push_back(l);
        vi.push_back(v);
    }

    for (int i = 0; i < vi.size(); i++)
    {
        string l = vi[i][0];
        if (l == "PUSH")
        {
            int p = stoi(vi[i][1]);
            a.push(p);
        }
        else if (l == "TOP")
            cout << a.front() << endl;
        else if (l == "POP")
            a.pop();
        else if (l == "PRINT")
            a.print();
    }
    return 0;
}