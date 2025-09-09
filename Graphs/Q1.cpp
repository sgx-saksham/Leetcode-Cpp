#include <bits/stdc++.h>
using namespace std;
/*

8 8
1 2 3
1 3 4
3 4 7
3 7 1
7 8 3
4 8 2
2 5 6
2 6 5

*/

class Graph
{
private:
    void dfsG(int node, vector<pair<int, int>> AL[], vector<int> &vis, vector<int> &dfs)
    {
        dfs.push_back(node);
        vis[node] = 1;
        for (auto i : AL[node])
        {
            int f = i.first;
            if (!vis[f])
                dfsG(f, AL, vis, dfs);
        }
    }

public:
    int n, m;
    void PrintList(vector<pair<int, int>> AL[])
    {
        int t = n, i = 0;
        while (t--)
        {
            if (i != 0)
            {
                cout << i << " : ";
                for (auto it : AL[i])
                    cout << "{" << it.first << "," << it.second << "}\t";
                cout << endl;
            }
            i++;
        }
    }
    vector<int> BFS(vector<pair<int, int>> AL[], int p)
    {
        vector<int> vis(n, 0), bfs;
        vis[p] = 1;
        queue<int> q;
        q.push(p);
        while (!q.empty())
        {
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            for (auto i : AL[node])
            {
                if (vis[i.first] == 0)
                {
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return bfs;
    }

    vector<int> DFS(vector<pair<int, int>> AL[], int p)
    {
        vector<int> vis(n, 0), dfs;
        vis[0] = 1;
        dfsG(p, AL, vis, dfs);
        return dfs;
    }
    void Print(vector<int> traversal)
    {
        for (auto i : traversal)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    Graph g;
    cin >> g.n >> g.m;
    g.n++;
    vector<pair<int, int>> AL[g.n];
    for (int i = 0; i < g.m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }
    vector<int> bfs = g.BFS(AL, 1), dfs = g.DFS(AL, 1);
    g.PrintList(AL);
    cout << "BFS : ";
    g.Print(bfs);
    cout << "DFS : ";
    g.Print(dfs);
}