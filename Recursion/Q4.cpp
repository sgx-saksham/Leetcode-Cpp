#include <iostream>
#include <vector>
#include <numeric>
#include <time.h>
using namespace std;

void sub(int i, vector<int> v, vector<int> f, int n, vector<vector<int>> &vi, int sum, int t)
{
    if (i == n)
    {
        if (sum == t)
            vi.push_back(f);
        return;
    }
    // case for take
    f.push_back(v[i]);
    sum = 0;
    for (int i = 0; i < f.size(); i++)
        sum += f[i];
    sub(i + 1, v, f, n, vi, sum, t);
    f.pop_back();
    sum = 0;
    for (int i = 0; i < f.size(); i++)
        sum += f[i];
    sub(i + 1, v, f, n, vi, sum, t);
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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> t;
    vector<vector<int>> vi;
    sub(0, v, f, n, vi, 0, t);
    for (auto i : vi)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}