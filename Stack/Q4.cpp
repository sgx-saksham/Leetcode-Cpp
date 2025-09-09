/*
    SGX is on the Code
    Nearest Greater to Left
    Q4 - NGL
*/
// 'NGL.cpp'
/*
2
4
1 3 2 4
7
1 3 0 0 1 2 4
*/
/*
2
4
4 2 3 1
7
4 2 1 0 0 3 1
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
vector<int> NGL_ON2(vector<int> v)
{
    vector<int> l;
    for (int i = 0; i <= v.size() - 1; i++)
    {
        bool f = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] > v[i])
            {
                l.push_back(v[j]);
                f = true;
                break;
            }
        }
        if (f == 0)
            l.push_back(-1);
    }
    return l;
}

vector<int> NGL(vector<int> v)
{
    vector<int> l;
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
            l.push_back(-1);
        else if ((!st.empty()) && st.top() > v[i])
            l.push_back(st.top());
        else if ((!st.empty()) && st.top() <= v[i])
        {
            while ((!st.empty()) && st.top() <= v[i])
                st.pop();
            if (st.empty())
                l.push_back(-1);
            else
                l.push_back(st.top());
        }
        st.push(v[i]);
    }
    return l;
}

vector<int> stacks(vector<int> arr)
{
    vector<int> v;
    stack<int> st;
    // for(int i=0;i<v.size(); i++)
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            v.push_back(-1);
        // else if(!st.empty() && st.top() > v[i])
        else if (!st.empty() && st.top() < arr[i])
            v.push_back(st.top());
        // else if(!st.empty() && st.top() <= arr[i])
        else if (!st.empty() && st.top() >= arr[i])
        {
            // while(!st.empty() && st.top() <= arr[i])
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n), l;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    l = NGL(v);
    for (auto &&i : l)
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