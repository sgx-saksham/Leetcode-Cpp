/*
    SGX is on the Code
*/
// 'trial1.cpp'
// Description of the code

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Type Names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
// Type Names Ends

// MACROS
// Loops
#define TC(t) while (t-- > 0)
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); (a)++)
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); (a)++)
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
// Maximum, Minimum and  Square
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
// Arrays
#define ALLA(arr, sz) arr, arr + sz
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define RESET(a, b) memset(a, b, sizeof(a))
// Vectors
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
// Macros ENDS

// Solving functions
void Solve(){
    // Your_code_goes_here
};

// Main Function / Driver Code
int main()

{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    TC(t)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}