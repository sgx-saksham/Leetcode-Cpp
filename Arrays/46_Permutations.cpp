/*
    SGX is on the Code
*/
// '46_Permutations.cpp'
/*
3
1,2,3
0,1
1
*/

#include <bits/stdc++.h>
using namespace std;

// Add typedefs or macros here

vector<vector<int>> permute(vector<int> v)
{
    vector<vector<int>> va;
    sort(v.begin(), v.end());
    do
    {
        va.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    return va;
}

void permute_rec(vector<int> v, int n, int total)
{
    int l = total / n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << v[i] << "\n";
        }
    }
}

void func(vector<int> v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    int a[n + 1];
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i * a[i - 1];
    }
    int total = a[n];
    permute_rec(v, n, total);
}

// Solving functions
void Solve()
{
    string s, o;
    cin >> s;
    int l = s.length();
    vector<int> a;
    char q[l], p[] = ",";
    strcpy(q, s.c_str());
    char *token = strtok(q, p);
    while (token)
    {
        o = token;
        a.push_back(stoi(o));
        token = strtok(NULL, p);
    }
    func(a);
    // vector<vector<int>> ai = permute(a);
    // for (int i = 0; i < ai.size(); i++)
    // {
    //     for (int j = 0; j < ai[i].size(); j++)
    //     {
    //         cout << ai[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (auto i : ai)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t-- > 0)
    {
        Solve();
    }

    return 0;
}