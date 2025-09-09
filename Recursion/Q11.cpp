/*
2
3
3 1 2
4
1 2 3 4
Q11 - Generate Permutations
*/
#include <bits/stdc++.h>
using namespace std;

class spacePermutation
{
public:
    int n;
    vector<int> v;
    void recSpace(vector<int> ds, vector<int> freq, vector<vector<int>> &ans)
    {
        if (ds.size() == n)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[i] == 0)
            {
                ds.push_back(v[i]);
                freq[i] = 1;
                recSpace(ds, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    void recOptimized(int ind, vector<vector<int>> &ans)
    {
        // pruning
        // base case
        if (ind == n)
        {
            ans.push_back(v);
            return;
        }
        // compute
        for (int i = ind; i < n; i++) // choices
        {
            swap(v[ind], v[i]);         // placing
            recOptimized(ind + 1, ans); // moving
            swap(v[ind], v[i]);         // revert back
        }
        // return ans;
    }
};

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ds, freq(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    spacePermutation d;
    d.n = n;
    d.v = v;
    vector<vector<int>> ans;
    d.recOptimized(0, ans);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Solve();
}