/*
Q6 - NSL index
7
6 2 5 4 5 1 6
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NSL_ind(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            k.push_back(-1);
        else if ((!s.empty()) && s.top().first < v[i])
            k.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first >= v[i])
        {
            while ((!s.empty()) && s.top().first >= v[i])
                s.pop();
            if (s.empty())
                k.push_back(-1);
            else
                k.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    return k;
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
    vector<int> NSL_index = NSL_ind(v);
    cout << endl;
    for (auto &&i : NSL_index)
        cout << i << "\t";
}