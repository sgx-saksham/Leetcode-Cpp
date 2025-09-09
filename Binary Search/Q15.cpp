/*
Q15 - Search in  row wise / column wise sorted matrix

4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
29
*/

#include <bits/stdc++.h>
using namespace std;

class BSearch
{
public:
    int n, m, t;
    vector<vector<int>> vi;
    pair<int, int> SearchMatrix()
    {
        int i = 0, j = m - 1;
        while (i >= 0 && i < n && j >= 0 && j < m)
        {
            if (vi[i][j] == t)
                return {i, j};
            else if (vi[i][j] > t)
                j--;
            else if (vi[i][j] < t)
                i++;
        }
        // cout << vi[i][j] << endl;
        return {-1, -1};
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    BSearch b;
    int x;
    cin >> b.n >> b.m;
    for (int i = 0; i < b.n; i++)
    {
        vector<int> v;
        for (int i = 0; i < b.m; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        b.vi.push_back(v);
    }
    cin >> b.t;
    cout << b.SearchMatrix().first << " " << b.SearchMatrix().second << endl;
}