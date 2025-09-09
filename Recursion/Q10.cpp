#include <bits/stdc++.h>
using namespace std;

class Subsets
{
public:
    void generateSubsetsViaBitManip(vector<vector<int>> &vi, vector<int> v)
    {
        // TC  : O((2^N)*N)
        int n = v.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> d;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) // i & 1, 2, 4
                    d.push_back(v[j]);
            vi.push_back(d);
        }
    }
    void generateSubsetsViaRecursion(vector<vector<int>> &vi, vector<int> v, vector<int> t, int i)
    {
        // TC  : O(2^N)
        if (i == v.size())
        {
            vi.push_back(t);
            return;
        }
        t.push_back(v[i]);
        generateSubsetsViaRecursion(vi, v, t, i + 1);
        t.pop_back();
        generateSubsetsViaRecursion(vi, v, t, i + 1);
    }
    void generateSubsetsViaBacktracking(vector<vector<int>> &vi, vector<int> v, vector<int> t, int i)
    {
        // TC  : O(2^N)
        if (i == v.size())
        {
            vi.push_back(t);
            return;
        }
        generateSubsetsViaBacktracking(vi, v, t, i + 1);
        t.push_back(v[i]);
        generateSubsetsViaBacktracking(vi, v, t, i + 1);
        t.pop_back();
    }
    void PrintSubsets(vector<vector<int>> &vi)
    {
        for (int i = 0; i < vi.size(); i++)
        {
            if (vi[i].empty())
                cout << "{}";
            for (int j = 0; j < vi[i].size(); j++)
                cout << vi[i][j] << " ";
            cout << endl;
        }
    }
    void SortSubsets(vector<vector<int>> &vi)
    {
        sort(vi.begin(), vi.end());
        for (int i = 0; i < vi.size(); i++)
            sort(vi[i].begin(), vi[i].end());
    }
    void EraseDuplicates(vector<vector<int>> &vi)
    {
        vi.erase(unique(vi.begin(), vi.end()), vi.end());
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
    vector<int> v(n), t;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> vi;
    Subsets S;
    // S.generateSubsetsViaBacktracking(vi, v, t, 0);
    // S.generateSubsetsViaRecursion(vi, v, t, 0);
    S.generateSubsetsViaBitManip(vi, v);
    S.SortSubsets(vi);
    S.EraseDuplicates(vi);
    S.PrintSubsets(vi);
}