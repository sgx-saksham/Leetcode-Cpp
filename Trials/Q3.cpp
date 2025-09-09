#include <bits/stdc++.h>
using namespace std;

void merger(int i, int j, int n, int m, vector<int> v, vector<int> w, vector<int> &p)
{
    if (i >= n)
    {
        for (int k = j; k < m; k++)
            p.push_back(w[k]);
        return;
    }
    if (j >= m)
    {
        for (int k = i; k < n; k++)
            p.push_back(v[k]);
        return;
    }
    if (v[i] < w[j])
    {
        p.push_back(v[i]);
        merger(i + 1, j, n, m, v, w, p);
    }
    else
    {
        p.push_back(w[j]);
        merger(i, j + 1, n, m, v, w, p);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(m), p;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> w[i];
    merger(0, 0, n, m, v, w, p);
    for (auto i : p)
        cout << i << " ";
    cout << endl;
}