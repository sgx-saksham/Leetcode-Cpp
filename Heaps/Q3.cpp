/*
Q3 - Sort a K sorted Array
7
6 5 3 2 8 10 9
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n, k;
    vector<int> v, s;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void sorted()
    {
        for (int i = 0; i < n; i++)
        {
            minHeap.push(v[i]);
            if (minHeap.size() > k)
            {
                s.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        while (minHeap.size() > 0)
        {
            s.push_back(minHeap.top());
            minHeap.pop();
        }
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
    p.sorted();
    for (auto i : p.s)
        cout << i << " ";
    cout << endl;
}