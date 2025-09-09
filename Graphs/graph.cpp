/*
    SGX is on the Code
*/
// 'graph.cpp'
/*
1
6    5
2    6
1    2
1    3
4    1
4    5
*/

//

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
void BiDirectional()
{
    int nodes, edges, a, b;
    cin >> nodes >> edges;
    vector<pair<int, int>> v;
    vector<int> AL[nodes];
    vector<vector<int>> AM(nodes, vector<int>(nodes, 0));
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    cout << "Adjacency List:\n";
    for (int i = 0; i < edges; i++)
    {
        a = v[i].first;
        b = v[i].second;
        AL[a - 1].push_back(b);
        AL[b - 1].push_back(a);
    }
    for (auto &&i : AL)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < edges; i++)
    {
        a = v[i].first - 1;
        b = v[i].second - 1;
        AM[a][b] = 1;
        AM[b][a] = 1;
    }
    for (auto &&i : AM)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
};

void UniDirectional()
{
    int nodes, edges, a, b;
    cin >> nodes >> edges;
    vector<pair<int, int>> v;
    vector<int> AL[nodes];
    vector<vector<int>> AM(nodes, vector<int>(nodes, 0));
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    cout << "Adjacency List:\n";
    for (int i = 0; i < edges; i++)
    {
        a = v[i].first;
        b = v[i].second;
        AL[a - 1].push_back(b);
    }
    for (auto &&i : AL)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < edges; i++)
    {
        a = v[i].first - 1;
        b = v[i].second - 1;
        AM[a][b] = 1;
    }
    for (auto &&i : AM)
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
        BiDirectional();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}