/*
// Q4 Get the number of prime Factors
5
2
3
5
7
17
*/

#include <bits/stdc++.h>
using namespace std;

class Sieve
{
public:
    vector<int> sieve;
    int N = 10000000, n;
    Sieve()
    {
        sieve.resize(N + 1, 1);
    }
    void CreateSieve()
    {
        for (int i = 2; (i * i) <= N; i++)
        {
            if (sieve[i])
            {
                for (int j = (i * i); j <= N; j += i)
                {
                    if (sieve[j] != 0)
                    {
                        sieve[i]++;
                        // sieve[j] = 0;
                    }
                }
            }
        }
    }
    int getNumberOfPrimes()
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
        cout << S.getNumberOfPrimes() << endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
