/*
2
7
4
*/
#include <bits/stdc++.h>
using namespace std;

class DPqueen
{
public:
    int n;
    vector<int> queen;
    DPqueen(int p, int q)
    {
        for (int i = 0; i < p; i++)
            queen.push_back(q);
    }
    bool check(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            int prow = i;
            int pcol = queen[i];
            if (pcol == col || abs(col - pcol) == abs(row - prow))
                return 0;
        }
        return 1;
    }
    int rec(int level) // level
    {
        // pruning
        // base case
        if (level == n)
            return 1;
        // compute
        int ans = 0;
        for (int col = 0; col < n; col++) // iterating choices
        {
            if (check(level, col)) // checking the choices
            {
                queen[level] = col; // moving the queen
                int ways = rec(level + 1);
                ans += ways;
                queen[level] = -1;
                // cout << "ways: " << ways << endl;
                // for (auto j : queen)
                //     cout << j << "\t";
                // cout << endl;
                // cout << endl;
            }
        }
        // return the ans
        return ans;
    }
};

void Solve()
{
    int n;
    cin >> n;
    DPqueen d(n, -1);
    d.n = n;
    int k = d.rec(0);
    cout << n << " : " << k << "\n--------\n";
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