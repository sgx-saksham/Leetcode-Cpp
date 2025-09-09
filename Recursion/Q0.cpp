/*
    SGX is on the Code
*/
// '0_Fibonacci.cpp'
/*
1
15
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Solving functions
long long fib_rec(long long n)
{
    // cout << "\nRecursive approach\nTC: O(2^n)\tSC: O(n)\tStack_Space:O(n)";
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    long long a = fib_rec(n - 1);
    long long b = fib_rec(n - 2);
    return a + b;
}

long long fib_dp(long long n, vector<int> v)
{
    // cout << "\nRecursive DP\nTC: O(n)\tSC: O(n)\tStack_Space:O(n)";
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    if (v[n] != -1)
        return v[n];

    long long a = fib_dp(n - 1, v);
    long long b = fib_dp(n - 2, v);
    v[n] = a + b;
    return v[n];
}

long long fib_iterative_dp(long long n)
{
    cout << "\nIterative DP\nTC: O(n)\tSC: O(n)\tStack_Space:O(1)\n";
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    long long a[n + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

long long fib_iterative_dp_space_optimized(long long n)
{
    cout << "\nIterative DP Space Optimized\nTC: O(n)\tSC: O(1)\tStack_Space:O(1)\n";
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    long long a = 0, b = 1, c;
    for (int i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fib_formula(long long n)
{
    cout << "\nFormula for fibonacci\nTC: O(1)\tSC: O(1)\tStack_Space:O(1)\n";
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    float f = sqrt(5);
    float a = pow((1 + f) / 2, n);
    float b = pow((1 - f) / 2, n);
    long long sum = (a - b) / f;
    return sum;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, -1);
    cout << "Fibonacci Series all Approaches for: " << n << endl;
    cout << "\nRecursive approach\nTC: O(2^n)\tSC: O(n)\tStack_Space:O(n)\n";
    cout << "Ans: " << fib_rec(n) << endl;
    cout << "\nRecursive DP\nTC: O(n)\tSC: O(n)\tStack_Space:O(n)\n";
    cout << "Ans: " << fib_dp(n, v) << endl;
    cout << "Ans: " << fib_iterative_dp(n) << endl;
    cout << "Ans: " << fib_iterative_dp_space_optimized(n) << endl;
    cout << "Ans: " << fib_formula(n) << endl;
    cout << "--------------------------\n";
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
    cerr << (float)clock() << endl;
    cerr << CLOCKS_PER_SEC << endl;
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}