/*
Q2 - DP Climbing stair
3
13
9
6
*/
#include <bits/stdc++.h>
using namespace std;

class DPstairs
{
    vector<int> v = {8, -1};

public:
    int n;
    int rec(int level)
    {
        // level means stairs to be jumped

        // pruning the fall off cases
        if (level > n)
            return 0;
        // base case
        if (level == n)
            return 1;
        // store the ans that will be returned
        int ans = 0;

        for (int step = 1; step <= 3; step++) // choice game
            if (level + step <= n)            // check game
                ans += rec(level + step);     // move game
        return ans;
    }
};

void Solve()
{
    int n;
    cin >> n;
    DPstairs d;
    d.n = n;
    cout << d.rec(1) << endl;
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