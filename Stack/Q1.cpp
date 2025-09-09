/*
    SGX is on the Code
    Nearest Greater to Right
    Next Greater Element
    Q1 - NGR
*/
// 'NGE.cpp'
/*
2
4
1 3 2 4
7
1 3 0 0 1 2 4
*/
/*
2
7
3 3 3 2 3 2 2
7
3 3 3 2 3 2 2
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

vector<int> NGE_ON2(vector<int> v)
{
    vector<int> k;
    bool f;
    for (int i = 0; i < v.size(); i++)
    {
        f = false;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                k.push_back(v[j]);
                f = true;
                break;
            }
        }
        if (f == false)
            k.push_back(-1);
    }
    return k;
}

vector<int> NGE_ON(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            k.push_back(-1);
        else if ((!st.empty()) && st.top() > v[i])
            k.push_back(st.top());
        else if ((!st.empty()) && st.top() <= v[i])
        {
            while ((!st.empty()) && st.top() <= v[i])
                st.pop();
            if (st.empty())
                k.push_back(-1);
            else
                k.push_back(st.top());
        }
        st.push(v[i]);
    }
    reverse(k.begin(), k.end());
    return k;
}

vector<int> NEXT(vector<int> v)
{
    vector<int> st, ans;
    for (int i = 0; i < v.size(); i++)
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(-1);
            else if (!st.empty() && st.back() > v[i])
                ans.push_back(st.back());
            else if (!st.empty() && st.back() <= v[i])
            {
                while (!st.empty() && st.back() <= v[i])
                    st.pop_back();
                if ()
            }
        }
}

void Solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n), l;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    l = NGE_ON2(v);
    for (auto i : l)
        cout << i << " ";
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