/*
Q7 - NSR index
7
6 2 5 4 5 1 6
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NSR_ind(vector<int> v)
{
    vector<int> k;
    int n = v.size();
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            k.push_back(n);
        else if ((!s.empty()) && s.top().first < v[i])
            k.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first >= v[i])
        {
            while ((!s.empty()) && s.top().first >= v[i])
                s.pop();
            if (s.empty())
                k.push_back(n);
            else
                k.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    reverse(k.begin(), k.end());
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
    vector<int> NSR_index = NSR_ind(v);
    cout << endl;
    for (auto &&i : NSR_index)
        cout << i << "\t";
}