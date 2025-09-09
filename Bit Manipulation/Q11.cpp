/*
Q11 - Get the Two numbers appearing once from the array in which all the other elements appears twice
10
2 1 2 5 1 4 4 7 3 3
*/

#include <bits/stdc++.h>
using namespace std;

int getRightMostSetBit(int n)
{
    int c = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
            return c;
        c++;
        n >>= 1;
    }
    return 0;
}
void getTwoNumAppearingOnce(vector<int> v)
{
    int x = 0, l = 0, r = 0;
    for (int i = 0; i < v.size(); i++)
        x ^= v[i];
    int mask = 1 << (getRightMostSetBit(x));
    for (int i = 0; i < v.size(); i++)
    {
        if (mask & v[i])
            l ^= v[i];
        else
            r ^= v[i];
    }
    cout << l << " " << r << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x = 0, l, r;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    getTwoNumAppearingOnce(v);
}