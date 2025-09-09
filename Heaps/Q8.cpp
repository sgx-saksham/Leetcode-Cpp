/*
Q8 - Connect Ropes to minimize the cost
5
1 2 3 4 5

*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n;
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void ConnectRopes()
    {
        int total = 0;
        for (int i = 0; i < n; i++)
            minHeap.push(v[i]);

        while (minHeap.size() >= 2)
        {
            int f = minHeap.top();
            minHeap.pop();
            int s = minHeap.top();
            minHeap.pop();
            total += f + s;
            minHeap.push(f + s);
        }
        cout << total << endl;
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
    p.ConnectRopes();
}