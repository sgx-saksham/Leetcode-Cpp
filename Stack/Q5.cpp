/*
Q5 - NGL index
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
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> NGL_index = NGL_ind(v);
    for (auto &&i : v)
        cout << i << "\t";
    cout << endl;
    for (auto &&i : NGL_index)
        cout << i << "\t";
}