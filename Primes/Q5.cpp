#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Sieve
{
public:
    vector<int> sieve;
    vector<int> v;
    int N = 10000000, n;
    Sieve()
    {
        for (int i = 0; i < N + 1; i++)
            sieve.push_back(i);
    }
    void CreateSieve()
    {
        for (int i = 2; (i * i) <= N; i++)
        {
            if (sieve[i] == i)
                for (int j = (i * i); j <= N; j += i)
                    if (sieve[j] == j)
                        sieve[j] = i;
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
    void PrimeFactor()
    {
        for (int i = 2; (i * i) <= n; i++)
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n /= i;
            }
        }
        if (n > 1)
            cout << n;
        cout << endl;
    }
    void PrimeFactorStriver()
    {
        while (n != 1)
        {
            cout << sieve[n] << " ";
            n /= sieve[n];
        }
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
        S.n = n;
        S.PrimeFactorStriver();
        cout << endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}