/*
Q11 - Max Area Rectangle of Binary Matrix
MARBM
2
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/
#include "stack_saksham.hpp"

int MAH(vector<int> height)
{
    int n = height.size();
    vector<int> NSR = NSR_ind(height);
    vector<int> NSL = NSL_ind(height);
    vector<int> width(n), area(n);
    for (int i = 0; i < n; i++)
        width[i] = NSR[i] - NSL[i] - 1;
    for (int i = 0; i < n; i++)
        area[i] = height[i] * width[i];
    return *max_element(area.begin(), area.end());
}

int MARBM(vector<vector<int>> matrix)
{
    vector<int> ds;
    for (int i = 0; i < matrix[0].size(); i++)
        ds.push_back(matrix[0][i]);
    int mx = MAH(ds);
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
                ds[j] = 0;
            else
                ds[j] += 1;
        }
        mx = max(mx, MAH(ds));
        cout << mx << " ";
    }
    cout << endl;
    return mx;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vi(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> vi[i][j];
    }
    cout << MARBM(vi) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Solve();
}