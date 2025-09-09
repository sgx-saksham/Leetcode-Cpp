#include <bits/stdc++.h>
using namespace std;

class Permutation
{
public:
    int n;
    vector<int> v;
    vector<vector<int>> vi;
    void permute(int i)
    {
        if (i >= n)
        {
            vi.push_back(v);
            return;
        }
        for (int j = i; j < n; i++)
        {
            swap(v[i], v[j]);
            permute(i + 1);
            swap(v[i], v[j]);
        }
    }
    void Print()
    {
        for (auto i : vi)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int t;
    Permutation p;
    cin >> p.n;
    for (int i = 0; i < p.n; i++)
    {
        cin >> t;
        p.v.push_back(t);
    }
    p.permute(0);
    p.Print();
}