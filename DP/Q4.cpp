/*
Q4 - DP workshop
1
5
3 5 4 2 1
3 4 1 3 1
6 2
*/
#include <bits/stdc++.h>
using namespace std;

class DPworkshop
{
public:
    int x, k, n;
    vector<int> t, s, taken;
    DPworkshop()
    {
        for (int i = 0; i < 1000; i++)
            taken.push_back(0);
    }
    bool check(int level)
    {
        int time = 0;
        int item = 0;
        for (int i = 0; i < level; i++)
        {
            if (taken[i])
            {
                time += t[i];
                item++;
            }
        }
        time += t[level];
        item++;
        return ((time <= x) && (item <= k));
    }
    int rec(int level)
    { // max skill I can make from [level --- n-1];
        // level is current item in [0 --- n-1]
        // pruning

        // base case
        if (level == n)
            return 0;
        // compute
        // Choice : not take
        int ans = rec(level + 1);
        // Choice : take
        if (check(level))
        {
            taken[level] = 1;
            ans = max(ans, (s[level] + rec(level + 1)));
            taken[level] = 0;
        }
        // return the computed ans
        return ans;
    }
};

void Solve()
{
    int x, k, n;
    cin >> n;
    DPworkshop d;
    vector<int> t(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> x >> k;
    d.n = n;
    d.t = t;
    d.s = s;
    d.x = x;
    d.k = k;
    cout << d.rec(0) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--)
        Solve();
}