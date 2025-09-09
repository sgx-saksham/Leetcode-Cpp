/*
    SGX is on the Code
*/
// '1_Bubble_Sort.cpp'
/*
Test Cases for the code
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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i] << " " << a[j] << endl;
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
            cout << a[i] << " " << a[j] << endl;
            cout << "\n";
        }
        cout << "NewLine\n\n";
    }
    cout << endl;
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