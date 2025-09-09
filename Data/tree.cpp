/*
    SGX is on the Code
*/
// 'tree.cpp'
/*
2
5
13
4
7
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
int climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }

    int one = climbStairs(n - 1);
    int two = climbStairs(n - 2);
    int three = climbStairs(n - 3);

    return one + two + three;
    // int a = 1;
    // int b = 2;
    // int c = 3;
    // int result = 0;

    // for (int i = 2; i < n; i++)
    // {
    //     result = a + b + c;
    //     a = b;
    //     b = c;
    //     c = result;
    // }
    // return result;
}
// Solving functions
void Solve()
{
    int n;
    cin >> n;
    int a = climbStairs(n);
    cout << a << endl;
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