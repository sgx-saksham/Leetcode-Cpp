/*
Q0 - Graph Representation using AM and AL

1
6    5
2    6
1    2
1    3
4    1
4    5

*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int nodes, edges, a, b;
    vector<vector<int>> AL;
    vector<vector<int>> AM;
    vector<pair<int, int>> v;
    void matrixResize()
    {
        AM.resize(nodes, vector<int>(nodes, 0));
        for (int i = 0; i < edges; i++)
        {
            a = v[i].first - 1;
            b = v[i].second - 1;
            AM[a][b] = 1;
            AM[b][a] = 1;
        }
    }
    void ListResize()
    {
        AL.resize(nodes);
        for (int i = 0; i < edges; i++)
        {
            a = v[i].first;
            b = v[i].second;
            AL[a - 1].push_back(b);
            AL[b - 1].push_back(a);
        }
    }
    void printMatrix()
    {
        cout << "Adjacency Matrix:\n\n";
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
                cout << AM[i][j] << " ";
            cout << endl;
        }
        cout << "\n--------------------------\n";
    }
    void PrintList()
    {
        int c = 1;
        cout << "Adjacency List:\n\n";
        for (auto &&i : AL)
        {
            cout << c << ": ";
            for (auto &&j : i)
                cout << j << " ";
            cout << endl;
            c++;
        }
        cout << "\n--------------------------\n";
    }
};

void Solve()
{
    Graph g;
    int u, v;
    cin >> g.nodes >> g.edges;
    for (int i = 0; i < g.edges; i++)
    {
        cin >> u >> v;
        g.v.push_back({u, v});
    }
    g.matrixResize();
    g.ListResize();
    g.printMatrix();
    g.PrintList();
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Solve();
}