/*
    SGX is on the Code
*/
// '3_Combination_Sum_1.cpp'
/*
2
4
2 3 6 7
7
4
1 2 3 4
10
*/

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Comb(int i, int t, vector<int> v, vector<int> f, vector<vector<int>> &vi)
{
    if (i == v.size())
    {
        if (t == 0)
        {
            vi.push_back(f);
            return;
        }
        else
            return;
    }
    if (v[i] <= t)
    {
        f.push_back(v[i]);
        Comb(i, t - v[i], v, f, vi);
        f.pop_back();
    }
    Comb(i + 1, t, v, f, vi);
}

void Solve()
{
    int n, t;
    cin >> n;
    vector<int> v(n), f;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> t;
    vector<vector<int>> vi;
    Comb(0, t, v, f, vi);
    for (auto &&i : vi)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
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