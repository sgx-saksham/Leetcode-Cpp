/*
    SGX is on the Code
*/
// '00_Trials.cpp'
/*
Test Cases for the code
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
bool isIsomorphic(string s, string t)
{
    unordered_map<char, int> m1, o1;
    vector<pair<char, int>> m, o;
    for (int i = 0; i < s.length(); i++)
    {
        pair<char, int> p = make_pair(s[i], i), l = make_pair(t[i], i);
        m1.insert(p);
        o1.insert(l);
        m.push_back(p);
        o.push_back(l);
    }
    if (m1.size() != o1.size())
        return false;
    for (auto &&i : m1)
    {
        cout << i.first << " " << i.second << " ";
    }
    cout << "\n";
    for (auto &&i : o1)
    {
        cout << i.first << " " << i.second << " ";
    }
    cout << "\n";
}
// Solving functions
void Solve()
{
    string s, t;
    cin >> s >> t;
    // cout << s << " " << t << endl;
    isIsomorphic(s, t);
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