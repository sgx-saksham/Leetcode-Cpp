/*	Saksham is on the Code */
/* Course Schedule */
/* Cycle Detection using BFS/DFS */
/*
Test case for najayaz (cycle detected)
7 7
1 2
2 5
5 7
3 1
3 4
6 3
6 7
*/
/*
Test Case for Apna Khoon (No cycle found)
5 4
1 2
2 3
2 5
3 4
*/
// 'Q3.cpp'

#include <bits/stdc++.h>
using namespace std;

bool detectViaDFS(int node, int parent, vector<bool> &visited, vector<vector<int>> &AL)
{
    visited[node] = true;
    for (auto i : AL[node])
    {
        if (!visited[i])
        {
            if (detectViaDFS(i, node, visited, AL))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}

bool CycleDFS(vector<vector<int>> AL)
{
    vector<bool> visited(AL.size(), false);
    visited[0] = true;
    for (int i = 1; i < AL.size(); i++)
        if (!visited[i])
            if (detectViaDFS(i, -1, visited, AL))
                return true;
    return false;
}

bool detectViaBFS(vector<vector<int>> &AL, int start, vector<bool> &visited)
{
    visited[start] = true;
    queue<pair<int, int>> q;
    q.push({start, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto i : AL[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, node});
            }
            else if (visited[i] && parent != i)
            {
                return true;
            }
        }
    }
    return false;
}
bool CycleBFS(vector<vector<int>> AL)
{
    vector<bool> visited(AL.size(), false);
    visited[0] = true;
    for (int i = 1; i < AL.size(); i++)
        if (!visited[i])
            if (detectViaBFS(AL, i, visited))
                return true;
    return false;
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
    if (CycleDFS(AL))
        cout << "Najayaz\n";
    else
        cout << "Khud ka khoon hai\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " : ";
    //     for (auto j : AL[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
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