/*	Saksham is on the Code */
/* No of provinces */
// 'Q4.cpp'

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
        if (adj[node][i] == 1 && visited[i] == false)
            DFS(adj, visited, i);
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<bool> visited(V, false);
    int c = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false)
        {
            c++;
            DFS(adj, visited, i);
        }
    }
    return c;
}

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (auto &i : adj)
        for (auto &j : i)
            cin >> j;
    cout << numProvinces(adj, n);
};

// Main Function / Driver Code
int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    Solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}