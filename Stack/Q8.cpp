/*
Q8 - NGR index
7
100 80 60 70 60 75 85
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NGR_ind(vector<int> v)
{
    vector<int> l;
    stack<pair<int, int>> s;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.empty())
            l.push_back(-1);
        else if ((!s.empty()) && s.top().first > v[i])
            l.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first <= v[i])
        {
            while ((!s.empty()) && s.top().first <= v[i])
                s.pop();
            if (s.empty())
                l.push_back(-1);
            else
                l.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    reverse(l.begin(), l.end());
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
    for (auto &&i : v)
        cout << i << "\t";
    cout << endl;
    vector<int> NGR_index = NGR_ind(v);
    for (auto &&i : NGR_index)
        cout << i << "\t";
}