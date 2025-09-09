/*
    SGX is on the Code
*/
// 'Q12.cpp'
/*
1
7
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

class nQueen
{
public:
    int n;
    vector<vector<string>> ans;

    bool Check(vector<string> &v, int r, int c)
    {
        for (int i = 0; i < c; i++)
            if (v[r][i] == 'Q')
                return false;

        for (int i = r, j = c; i >= 0 and j >= 0; i--, j--)
            if (v[i][j] == 'Q')
                return false;

        for (int i = r, j = c; j >= 0 and i < n; i++, j--)
            if (v[i][j] == 'Q')
                return false;

        return true;
    }

    void solve(vector<string> &v, int c)
    {
        if (c >= n)
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (Check(v, i, c))
            {
                v[i][c] = 'Q';
                solve(v, c + 1);
                v[i][c] = '-';
            }
        }
    }

    vector<vector<string>> solveNQueen()
    {
        vector<string> v(n, string(n, '-'));
        solve(v, 0);
        return ans;
    }
};

// Solving functions
void Solve()
{
    nQueen q;
    cin >> q.n;
    vector<vector<string>> vi = q.solveNQueen();
    for (auto &&i : vi)
    {
        for (auto &&j : i)
        {
            cout << j << "\n";
        }
        cout << endl;
    }
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}