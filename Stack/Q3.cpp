/*
    SGX is on the Code
    Q3 - NSL
*/
// 'NSL.cpp'
/*
5
4
1 3 2 4
7
1 3 0 0 1 2 4
5
8 4 6 2 3
5
4 5 2 10 8
4
10 1 1 6
*/
/*
7
4
1 3 2 4
7
1 3 0 0 1 2 4
5
8 4 6 2 3
5
4 5 2 10 8
5
10 1 1 6 0
5
8 4 6 2 3
7
1 1 1 1 1 1 1
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

// vector<int> NSL_ON2(vector<int> v)
// {
//     return v;
// }
// vector<int> NSR_ON2(vector<int> prices)
// {
//     vector<int> v;
//     stack<int> st;
//     for (int i = prices.size() - 1; i >= 0; --i)
//     {
//         if (st.empty())
//             v.push_back(prices[i]);
//         else if (st.top() < prices[i] && !st.empty())
//             v.push_back(prices[i] - st.top());
//         else if (st.top() >= prices[i] && !st.empty())
//         {
//             while (st.top() >= prices[i] && !st.empty())
//                 st.pop();
//             if (st.empty())
//                 v.push_back(prices[i]);
//             else
//                 v.push_back(prices[i] - st.top());
//         }
//         st.push(prices[i]);
//     }
//     reverse(v.begin(), v.end());
//     return v;
// }

vector<int> NSL(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.size() == 0)
            k.push_back(-1);
        else if ((!st.empty()) && st.top() < v[i])
            k.push_back(st.top());
        else if ((!st.empty()) && st.top() >= v[i])
        {
            while ((!st.empty()) && st.top() >= v[i])
                st.pop();
            if (st.size() == 0)
                k.push_back(-1);
            else
                k.push_back(st.top());
        }
        st.push(v[i]);
    }
    return k;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n), l;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    l = NSL(v);
    for (auto &&i : l)
        cout << i << " ";
    cout << endl;
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
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}