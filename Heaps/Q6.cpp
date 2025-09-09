/*
Q6 - Frequency Sort
17
1 1 1 2 3 2 4 4 8 8 8 8 6 6 6 6 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n;
    vector<int> v, k;
    priority_queue<pp, vector<pp>, greater<pp>> maxHeap;
    unordered_map<int, int> m;
    void frequencySort()
    {
        for (auto i : v)
            m[i]++;
        for (auto i : m)
            maxHeap.push({i.second, i.first});

        while (maxHeap.size() > 0)
        {
            cout << maxHeap.top().second << " " << maxHeap.top().first << endl;
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
    p.frequencySort();
}