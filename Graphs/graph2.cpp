/*	Saksham is on the Code */
/* Description of the code */
// 'graph2.cpp'

#include <bits/stdc++.h>
using namespace std;

void D(vector<vector<int>> AL, int node, vector<bool> &visited, vector<int> &dfs)
{
    visited[node] = true;
    dfs.push_back(node);
    for (auto i : AL[node])
        if (!visited[i])
            D(AL, i, visited, dfs);
}

vector<int> DFS(vector<vector<int>> AL, int start)
{
    vector<int> v;
    vector<bool> visited(AL.size(), false);
    visited[0] = true;
    D(AL, start, visited, v);
    return v;
}

vector<int> BFS(vector<vector<int>> AL, int start)
{
    vector<int> v;
    vector<bool> visited(AL.size(), false);
    visited[0] = true;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int a = q.front();
        v.push_back(a);
        q.pop();
        for (auto i : AL[a])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return v;
}

void Solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> AL(n + 1);
    for (int i = 0; i < e; i++)
    {
        int m1, m2;
        cin >> m1 >> m2;
        AL[m1].push_back(m2);
        AL[m2].push_back(m1);
    }
    vector<int> bfs = BFS(AL, 1);
    vector<int> dfs = DFS(AL, 1);
    for (auto i : dfs)
        cout << i << " ";
    cout << endl;
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
/*
1
30 40
1 2
1 3
2 4
2 5
2 6
3 4
4 6
4 12
5 7
6 7
6 8
6 9
6 10
6 28
8 28
9 10
9 11
10 17
10 20
10 21
10 22
12 13
12 14
12 15
12 16
14 15
15 18
15 23
16 17
18 19
19 20
21 22
22 24
23 24
24 25
25 26
25 27
27 28
27 29
27 30
*/