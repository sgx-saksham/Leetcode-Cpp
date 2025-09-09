/*
Q12 - Get all The Subsets of a given array
3
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSubsets(vector<int> v, int n)
{
    vector<vector<int>> vi;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> ds;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                ds.push_back(v[j]);
        }
        vi.push_back(ds);
    }
    sort(vi.begin(), vi.end());
    return vi;
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
    vector<vector<int>> vi = getSubsets(v, n);

    for (auto &&i : vi)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }
}