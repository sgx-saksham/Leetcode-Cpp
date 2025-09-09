/*
Q9 - Stock Span
7
100 80 60 70 60 75 85
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> NGL_ind(vector<int> v)
{
    vector<int> l;
    stack<int> st;
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            l.push_back(-1);
        else if (s.top().first > v[i] && !s.empty())
            l.push_back(s.top().second);
        else if (s.top().first <= v[i] && !s.empty())
        {
            while (s.top().first <= v[i] && !s.empty())
                s.pop();
            if (s.empty())
                l.push_back(-1);
            else
                l.push_back(s.top().second);
        }
        s.push({v[i], i});
    }

    return l;
}

void StockSpan(vector<int> v, int n)
{
    vector<int> getNGL = NGL_ind(v);
    for (int i = 0; i < getNGL.size(); i++)
        getNGL[i] = i - getNGL[i];

    for (auto i : v)
        cout << i << "\t";
    cout << endl;
    for (auto i : getNGL)
        cout << i << "\t";
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    StockSpan(v, n);
}