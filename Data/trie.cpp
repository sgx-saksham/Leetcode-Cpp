/*
    SGX is on the Code
*/
// 'trie.cpp'
/*
Test Cases for the code
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Print_vec(vector<int> &vec)
{
    for (auto &&i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
void Scan_vec(vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        int m;
        cin >> m;
        vec.push_back(m);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> v;
    Scan_vec(v, n);
    Print_vec(v, n);
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