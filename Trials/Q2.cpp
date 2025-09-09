/*
    SGX is on the Code
*/
// 'Q2.cpp'
/*
1
ADD NEVER
ADD COLLAR
INSERT CAT COLLAR
ADD DOG
ADD SCARES
INSERT ANYTHING CAT
REMOVE CAT
INSERT THAT SCARES
REMOVE COLLAR
INSERT WEAR ANYTHING
REMOVE DOG
ADD CAT
INSERT YOUR CAT
SHOW
*/

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

class StringVector
{
public:
    vector<string> v;
    void ADD(string s)
    {
        v.push_back(s);
    }
    void REMOVE(string s)
    {
        for (int i = 0; i < v.size(); i++)
            if (v[i] == s)
                v.erase(v.begin() + i);
    }
    void INSERT(string s, string t)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == t)
            {
                v.insert(v.begin() + i, s);
                break;
            }
        }
    }
    void SHOW()
    {
        if (v.empty())
        {
            cout << "0\n";
            return;
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
};

// Solving functions
void Solve()
{
    StringVector S;
    string s;
    vector<vector<string>> vi;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string l;
        vector<string> v;
        while (ss >> l)
            v.push_back(l);
        vi.push_back(v);
    }
    for (int i = 1; i < vi.size(); i++)
    {
        if (vi[i][0] == "ADD")
            S.ADD(vi[i][1]);
        else if (vi[i][0] == "INSERT")
            S.INSERT(vi[i][1], vi[i][2]);
        else if (vi[i][0] == "REMOVE")
            S.REMOVE(vi[i][1]);
        else if (vi[i][0] == "SHOW")
            S.SHOW();
        else
        {
            cout << "0\n";
            break;
        }
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
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}