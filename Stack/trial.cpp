/*
    SGX is on the Code
*/
// 'trial.cpp'
/*
3
5
3 1 1 2 3
7
1 1 2 2 3 3 4
17
1 1 1 2 2 2 3 3 3 4 4 5 7 7 7 7 7
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
vector<pair<int, int>> vec_stable(vector<int> v, map<int, int> m)
{
    vector<pair<int, int>> l;
    for (int j = 0; j < v.size(); j++)
    {
        for (auto i : m)
        {
            if (i.first == v[j])
                l.push_back({i.first, i.second});
        }
    }
    return l;
}
vector<int> vec_stable(vector<int> s)
{
    vector<int> v(s), l;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (s[i] == v[j])
            {
                l.push_back(s[i]);
                v.erase(v.begin() + j);
            }
        }
    }
    return l;
}

void funct()
{
    int n;
    cin >> n;
    vector<int> arr(n), v;
    vector<vector<int>> vi(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> map;
    for (auto it : arr)
    {
        map[it]++;
    }
    for (auto i : map)
        v.push_back(i.first);
    n = v.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(v[i] - v[j]);
            freq[diff]++;
        }
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vi[i].empty())
        // vi[i].push_back();
    }

    for (auto it : freq)
    {
        cout << it.first << ":" << it.second << endl;
    }
}

void Solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    map<int, vector<int>> mapped, stable_vector;
    vector<int> v(n), o(n), r, l, vi;
    vector<pair<int, int>> p;
    vector<pair<int, vector<int>>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    vector<int> stable = vec_stable(v);
    vector<pair<int, int>> stabled = vec_stable(stable, m);
    for (auto i : m)
    {
        p.push_back({i.second, i.first});
    }
    sort(p.begin(), p.end());
    for (auto i : p)
    {
        l.push_back(i.second);
        r.push_back(i.first);
    }
    int si = l.size();
    for (int j = 0, i = 1; i < si; i++, j++)
    {
        if (r[i] == r[j])
            vi.push_back(l[j]);
        else
        {
            vi.push_back(l[j]);
            mapped.insert({r[j], vi});
            vec.push_back({r[j], vi});
            vi.clear();
        }
        if (i == si - 1)
        {
            vi.push_back(l[i]);
            mapped.insert({r[i], vi});
            vec.push_back({r[i], vi});
        }
    }
    for (auto i : mapped)
    {
        cout << i.first << " , { ";
        for (auto j : i.second)
            cout << j << " ";
        cout << "}" << endl;
    }
    cout << endl;

    // for (auto i : vec)
    // {
    //     cout << i.first << " , { ";
    //     for (auto j : i.second)
    //         cout << j << " ";
    //     cout << "}" << endl;
    // }
    // cout << endl;

    for (auto &&i : stabled)
    {
        cout << i.first << " " << i.second << endl;
    }
    // for (auto &&i : stable)
    // {
    //     cout << i << " ";
    // }
    cout << ("\n\n");
    pow(1, n);
};
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