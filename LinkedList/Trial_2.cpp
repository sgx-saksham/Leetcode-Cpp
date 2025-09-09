/*
    SGX is on the Code
*/
// 'Trial_2.cpp'
/*

*/

// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Solve()
{
    int n, m;
    cin >> n;
    if (n % 2 == 0)
    {
        m = n;
        n /= 2;
        int a[m][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j = m / 2)
                    a[i][j] = m;
                else
                    a[i][j] = 0;
            }
        }
        // for (auto &&i : a)
        // {
        //     for (auto &&j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        m = n;
        n = (n + 1) / 2;
        int a[m][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j = m / 2)
                    a[i][j] = m;
                else
                    a[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout << "\n\n";
    // int c = 10, b = 20;
    // c ^= b;
    // b ^= c;
    // c ^= b;
    // cout << b << " " << c << endl;
};

void vec()
{
    int n;
}

void cream()
{
    vector<int> nums = {1, 2, 3, 4}, c;

    int n = nums.size();
    vector<int> p(nums[0], nums[1]);
    for (int i = 3; i < n; i += 2)
    {
        int f = nums[i - 1];
        int val = nums[i];
        vector<int> v(f, val);
        p.insert(p.end(), v.begin(), v.end());
    }
    for (auto i : p)
    {
        cout << i << " ";
    }
}
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
        cream();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}