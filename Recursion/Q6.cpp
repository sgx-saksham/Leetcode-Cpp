#include <bits/stdc++.h>

using namespace std;

int sub(int i, int t, vector<int> v, int sum, int n, vector<int> f, vector<vector<int>> &vi)
{
    if (i == n)
    {
        if (sum == t)
        {
            vi.push_back(f);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    sum += v[i];
    f.push_back(v[i]);
    int a = sub(i + 1, t, v, sum, n, f, vi);
    f.pop_back();
    sum -= v[i];
    int b = sub(i + 1, t, v, sum, n, f, vi);
    return a + b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n;
    vector<int> v(n, 0), f;
    vector<vector<int>> vi;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> t;
    int a = sub(0, t, v, 0, n, f, vi);
    for (auto i : vi)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << a;
}