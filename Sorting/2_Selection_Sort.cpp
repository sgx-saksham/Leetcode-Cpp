/*
    SGX is on the Code
*/
// '2_Selection_Sort.cpp'
/*
1
7
1 3 91 54 2 7 4
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Solve()
{
    int n, mine = INT_MAX;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        mine = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[mine])
            {
                mine = j;
            }
        }
        swap(a[i], a[mine]);
    }
    for (auto &&i : a)
    {
        cout << i << " ";
    }
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