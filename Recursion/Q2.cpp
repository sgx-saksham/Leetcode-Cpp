/*
    SGX is on the Code
*/
// '2_Print_Subsequence.cpp'
/*
2
3
3 1 2
4
1 2 3 4
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

// Solving functions
void SubSeq(int ind, vector<int> &ds, vector<int> v, int n, vector<vector<int>> &vi)
{
    if (ind == n)
    {
        if (ds.size() == 0)
        {
            vector<int> v(1, -1);
            vi.push_back(v);
            cout << "{}";
            cout << endl;
        }
        vi.push_back(ds);
        for (auto &&i : ds)
            cout << i << " ";
        cout << endl;
        return;
    }
    // Take the index
    ds.push_back(v[ind]);
    SubSeq(ind + 1, ds, v, n, vi);
    ds.pop_back();
    // Not take
    SubSeq(ind + 1, ds, v, n, vi);
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n, 0), ds;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> vi;
    SubSeq(0, ds, v, n, vi);

    // for (auto &&i : vi)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
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