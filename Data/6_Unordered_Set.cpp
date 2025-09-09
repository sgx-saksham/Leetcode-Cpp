/*
    SGX is on the Code
*/
// '6_Unordered_Set.cpp'
/*
1
10
1 2 5 3 4 3 4 3 8 6
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Solve()
{
    int n;
    cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    for (auto &&i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    // auto i = s.;
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