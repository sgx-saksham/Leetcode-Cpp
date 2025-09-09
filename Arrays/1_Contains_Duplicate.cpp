/*
    SGX is on the Code
*/
// '1_Contains_Duplicate.cpp'
/*
2
5
1 2 3 4 4
5
1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;

// Solving functions

bool containsDuplicate(vector<int> &nums)
{
    bool ans;
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto i : m)
    {
        if (i.second > 1)
            return true;
    }
    return false;
}

void Solve()
{
    int n, m;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }
    cout << containsDuplicate(v) << endl;
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