// Q15 - Implement Stack using a  array
#include <bits/stdc++.h>
using namespace std;

class StackArr
{
public:
    int a[100], t = -1;
    void push(int n)
    {
        t++;
        a[t] = n;
    }
    void pop()
    {
        if (t < 0)
            return;
        a[t] = 0;
        t--;
    }
    int top()
    {
        if (t < 0)
            return -1;
        return a[t];
    }
    void print()
    {
        if (t < 0)
        {
            cout << "empty\n";
            return;
        }
        for (int i = 0; i <= t; i++)
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

    StackArr a;
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
    // for (auto &&i : vi)
    // {
    //     for (auto &&j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < vi.size(); i++)
    {
        string l = vi[i][0];
        if (l == "PUSH")
        {
            int p = stoi(vi[i][1]);
            a.push(p);
        }
        else if (l == "TOP")
            cout << a.top() << endl;
        else if (l == "POP")
            a.pop();
        else if (l == "PRINT")
            a.print();
    }
    return 0;
}