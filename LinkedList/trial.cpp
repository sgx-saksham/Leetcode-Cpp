/*
    SGX is on the Code
*/
// 'trial.cpp'
/*
Test Cases for the code
*/

// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loo
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// Solving functions
void Solve()
{
    int n, temp;
    cin >> n;
    ordered_set x;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x.insert(temp);
    }

    // vector<int>
    for (auto &&i : x)
    {
        cout << i << " ";
    }
    cout << endl;
};

void cream()
{
    string s, p;
    cin >> s >> p;
    unordered_map<char, char> m;
    unordered_set<char> mapped;
    if (s.length() != p.length())
        cout << 0;
    for (int i = 0; i < s.length(); i++)
    {
        m.insert(make_pair(s[i], p[i]));
    }
    for (auto &&i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
}

void matrix()
{
    int n, m;
    cin >> n >> m;
    int rsum[n];
    int csum[m];
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // row wise sum
    for (int i = 0; i < n; i++)
    {
        rsum[i] = 0;
        for (int j = 0; j < m; j++)
        {
            rsum[i] += a[i][j];
        }
    }
    // coloum wise sum
    for (int i = 0; i < m; i++)
    {
        csum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            csum[i] += a[j][i];
        }
    }
    for (auto &&i : rsum)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto &&i : csum)
    {
        cout << i << " ";
    }
    int p = 5328;
    bitset<128> b(p);

    cout << b.to_string('-', '1') << "\n";
    // cout << __builtin_ctz() << endl;
}

int c = 0;
int rem(int n, int p, int c)
{
    if (n == p || n <= -200 || n >= 200)
        return 0;
    c++;
    int a = n + c, b = n - c;
    // cout << a << " " << b << endl;
    int one = rem(a, p, c);
    int two = rem(b, p, c);
    return min(one, two);
    // cout << one << endl;
}

void Rec()
{
    int n;
    cin >> n;
    cout << rem(0, n, 0) << endl;
}

// Main Function / Driver Code
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t--)
    {
        Rec();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}