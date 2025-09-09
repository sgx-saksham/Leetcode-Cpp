/*
    SGX is on the Code
*/
// '7_Combination_Sum_II.cpp'
//  Combination Sum II – Find all unique combinations
/*
2
7
10 1 2 7 6 1 5
8
5
2 5 2 1 2
5
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

void Comb(int i, int t, vector<int> v, vector<int> ds, vector<vector<int>> &vi)
{
    if (i == v.size())
    {
        if (t == 0)
            vi.push_back(ds);
        return;
    }
    if (v[i] <= t)
    {
        ds.push_back(v[i]);
        Comb(i + 1, t - v[i], v, ds, vi);
        ds.pop_back();
    }
    Comb(i + 1, t, v, ds, vi);
}

void Comb2(int ind, int t, vector<int> &v, vector<int> &ds, vector<vector<int>> &vi)
{
    if (t == 0)
    {
        vi.push_back(ds);
        return;
    }
    for (int i = ind; i < v.size(); i++)
    {
        if (i > ind && v[i] == v[i - 1])
            continue;
        if (v[i] > t)
            break;
        ds.push_back(v[i]);
        Comb2(i + 1, t - v[i], v, ds, vi);
        ds.pop_back();
    }
}
// void CombII(int ind, int t, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
// {
//     if (t == 0)
//     {
//         ans.push_back(ds);
//         return;
//     }
//     for (int i = ind; i < arr.size(); i++)
//     {
//         if (i > ind && arr[i] == arr[i - 1])
//             continue;
//         if (arr[i] > t)
//             break;
//         ds.push_back(arr[i]);
//         CombII(i + 1, t - arr[i], arr, ds, ans);
//         ds.pop_back();
//     }
// }
void Solve()
{
    int n, t;
    cin >> n;
    vector<int> v(n), ds;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> t;
    sort(v.begin(), v.end());
    vector<vector<int>> vi;
    Comb2(0, t, v, ds, vi);
    // int s = vi.size();
    // for (int i = 0; i < s; i++)
    //     sort(vi[i].begin(), vi[i].end());
    // sort(vi.begin(), vi.end());
    // vi.erase(unique(vi.begin(), vi.end()), vi.end());
    for (auto &&i : vi)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
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