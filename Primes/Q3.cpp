/*
Q3 Sieve through the primes
10
2741
1235
999983
2000
40
31
100
17
123
7
*/
#include <bits/stdc++.h>
using namespace std;

class Sieve
{
public:
    vector<bool> sieve;
    vector<int> v;
    int N = 10000000, n;
    Sieve()
    {
        sieve.resize(N + 1, true);
        sieve[0] = false;
    }
    void CreateSieve()
    {
        for (int i = 2; (i * i) <= N; i++)
        {
            if (sieve[i])
            {
                for (int j = (i * i); j <= N; j += i)
                    sieve[j] = false;
            }
        }
    }
    void SieveThroughPrimes()
    {
        for (int i = 2; i < sieve.size(); i++)
        {
            if (sieve[i])
                v.push_back(i);
        }
    }
    bool CheckPrime()
    {
        cout << n << "\t";
        return sieve[n];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    Sieve S;
    S.CreateSieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 0 || n == 1)
            cout << "NO\n";
        S.n = n;
        if (S.CheckPrime())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
