/*
Q12 - Rain Water Trapping
2
6
3 0 0 2 0 4
12
0 1 0 2 1 0 1 3 2 1 2 1
*/
#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> v, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = 0, mn = 0;
        l = *max_element(v.begin(), v.begin() + i);
        r = *max_element(v.begin() + i, v.end());
        mn = min(l, r) - v[i];
        if (mn > 0)
            sum += mn;
    }
    return sum;
}

int rainWater(vector<int> v)
{
    int n = v.size(), sum = 0;
    vector<int> l(n), r(n);
    l[0] = v[0];
    r[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
        l[i] = (max(l[i - 1], v[i]));
    for (int i = n - 2; i >= 0; i--)
        r[i] = (max(r[i + 1], v[i]));
    for (int i = 0; i < n; i++)
    {
        int mn = min(l[i], r[i]) - v[i];
        sum += mn;
    }
    return sum;
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << rainWater(v, n) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--)
        Solve();
}