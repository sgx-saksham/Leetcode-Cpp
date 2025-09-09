/*
Q5 - Top K frequent Numbers
7
1 1 1 2 3 2 4
2
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n, k;
    vector<int> v;
    priority_queue<pp, vector<pp>, greater<pp>> maxHeap;
    unordered_map<int, int> m;
    void frequent()
    {
        for (auto i : v)
            m[i]++;
        for (auto i : m)
        {
            maxHeap.push({i.second, i.first});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        while (maxHeap.size() > 0)
        {
            cout << maxHeap.top().second << " ";
            maxHeap.pop();
        }
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

    int t;
    PQ p;
    cin >> p.n;
    for (int i = 0; i < p.n; i++)
    {
        cin >> t;
        p.v.push_back(t);
    }
    cin >> p.k;
    p.frequent();
}