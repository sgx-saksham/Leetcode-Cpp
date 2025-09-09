#include <bits/stdc++.h>
using namespace std;

class SegmentedSieve
{
public:
    int l, r, N = 1000000;
    vector<bool> sieveSegmented;
    SegmentedSieve()
    {
        sieveSegmented.resize(N, true);
    }
    void CreateSieve()
    {
        for (int i = 2; i * i <= N; i++)
        {
            if (sieveSegmented[i])
                for (int j = i * i; j <= N; j += i)
                    sieveSegmented[j] = false;
        }
    }
    vector<int> GeneratePrimes(int sr)
    {
        vector<int> ds;
        for (int i = 2; i * i <= sr; i++)
            if (sieveSegmented[i])
                ds.push_back(i);
        return ds;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    SegmentedSieve S;
    S.CreateSieve();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> S.l >> S.r;
        vector<int> dummy((S.r - S.l) + 1, 1), primes;
        primes = S.GeneratePrimes(sqrt(S.r));
        for (auto i : primes)
        {
            int firstMultiples = (S.l / i) * i;
            if (firstMultiples < S.l)
                firstMultiples += i;
            for (int j = max(firstMultiples, i * i); j <= S.r; j += i)
                dummy[j - S.l] = 0;
        }
        for (int i = 0; i <= S.r; i++)
            if (dummy[i - S.l] == 1)
                cout << i << " ";
        cout << endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}