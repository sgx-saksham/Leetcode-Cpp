/*
Q1 Factors
7
6
5
13
28
3
36
128
*/
#include <bits/stdc++.h>
using namespace std;

class Factors
{
public:
    int n;
    void printFactors()
    {
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (n / i != i)
                    cout << i << " " << (n / i) << " ";
                else
                    cout << i << " ";
            }
        }
        cout << endl;
    }
    int countNumberOfFactors()
    {
        int c = 0;
        for (int i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
                c++;
                if (n / i != i)
                {
                    c++;
                }
            }
        }
        cout << endl;
        return c;
    }
    int sumOfFactors()
    {
        int s = 0;
        for (int i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                s += i;
                if (n / i != i)
                    s += (n / i);
            }
        }
        return s;
    }
};

void Solve()
{
    int n;
    cin >> n;
    Factors f;
    f.n = n;
    f.printFactors();
    // cout << f.pr << endl;
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