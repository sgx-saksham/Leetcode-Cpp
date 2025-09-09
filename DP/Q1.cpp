/*
    SGX is on the Code
*/
// '1_Sum_till_N.cpp'
/*
3
6
9
13
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

class SumTillN
{
public:
    int DP(int n)
    {
        int v[n + 1];
        v[0] = 1;
        for (int i = 1; i <= n; i++)
            v[i] = v[i - 1] + (i + 1);
        return v[n - 1];
    }

    int Iteration(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += i;
        return sum;
    }

    int Recursion(int n)
    {
        if (n == 1)
            return 1;
        int sum;
        return n + Recursion(n - 1);
    }

    int Formula(int n)
    {
        int sum = 0;
        sum = (n * (n + 1)) / 2;
        return sum;
    }
};
// Solving functions
void Solve()
{
    int n;
    cin >> n;
    SumTillN d;
    // cout << d.Recursion(n) << endl;
    // DP(n);
    // cout << Iteration(n) << endl;
    cout << d.DP(n) << endl;
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