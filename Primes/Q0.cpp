#include <bits/stdc++.h>
using namespace std;

class Primes
{
public:
    int n;
    bool checkPrimeByBruteForce()
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool checkPrimeBySqrtOptimized()
    {
        for (int i = 2; (i * i) < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

void Solve()
{
    int n;
    cin >> n;
    Primes P;
    P.n = n;
    cout << P.checkPrimeBySqrtOptimized() << " " << P.checkPrimeByBruteForce() << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Solve();
}