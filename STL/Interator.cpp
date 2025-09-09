/*
    SGX is on the Code
*/
// 'Interator.cpp'
/*

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
void Solve()
{
    // vector<int> v(19, 0);
    // vector<int>::iterator it;
    // it = v.begin() + 2;

    unordered_set<int> s;
    set<tuple<int, int, int>> ps;
    // set<int>::iterator i;
    // set<tuple<int, int, int>>::iterator p;
    // s.insert(9);
    ps.insert(make_tuple(3, 2, 1));
    ps.insert(make_tuple(1, 3, 2));
    ps.insert(make_tuple(2, 1, 3));
    ps.insert(make_tuple(2, 3, 1));
    ps.insert(make_tuple(1, 2, 3));
    ps.insert(make_tuple(3, 1, 2));
    // p = ps.begin();
    // sort(ps.begin(), ps.end());

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // cout << v.back();
    vector<int> v2 = {6, 7, 8, 9, 10}, v3;
    // v.insert((v.begin() - 1), v2.begin(), v2.end());
    // v.emplace_back(v2.begin())
    string s;
    s = "string os";
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : ps)
    {
        tuple<int, int, int> t = i;
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
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