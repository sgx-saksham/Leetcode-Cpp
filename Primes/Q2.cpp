/*
Q2 a!=b!=c!=1

3
64
28
256

*/

#include <bits/stdc++.h>
using namespace std;

class ABCequalsN
{
public:
    int n;
    bool Check()
    {
        int a = 1, b = INT_MAX, c = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a = i;
                break;
            }
        }
        n /= a;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i != a)
                    b = min(b, i);
                if ((n / i) != i)
                    b = min(b, n / i);
            }
        }
        c = n / b;
        if (a != b && b != c && c != a && c != 1)
        {
            cout << a << " " << b << " " << c << " ";
            return true;
        }
        return false;
    }
};

void Solve()
{
    ABCequalsN T;
    cin >> T.n;
    if (T.Check())
        cout << "Yes\n";
    else
        cout << "No\n";
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