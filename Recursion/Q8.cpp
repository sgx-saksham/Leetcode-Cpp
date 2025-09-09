#include <bits/stdc++.h>
using namespace std;

class SubsetSum
{
public:
    void SubsetSum1(vector<int> v, vector<int> &sum, int ind, int n, int s)
    {
        if (ind == n)
        {
            sum.push_back(s);
            return;
        }
        SubsetSum1(v, sum, ind + 1, n, s + v[ind]);
        SubsetSum1(v, sum, ind + 1, n, s);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n), sum;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    SubsetSum S;
    S.SubsetSum1(v, sum, 0, n, 0);
    for (auto i : sum)
        cout << i << "\n";
}