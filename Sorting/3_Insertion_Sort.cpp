/*
    SGX is on the Code
*/
// '3_Insertion_Sort.cpp'
/*
1
7
51 3 91 54 2 7 4
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Solve()
{
    int n, key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = a[i];
        while (key <= a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
    for (auto &&i : a)
    {
        cout << i << " ";
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