/*
Q2 - Kth largest Elements in array
6
7 10 4 3 20 15
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n, k;
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void KLargestElements()
    {
        if (n < k)
        {
            cout << "-1";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            minHeap.push(v[i]);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        while (minHeap.size() > 0)
        {
            cout << minHeap.top() << " ";
            minHeap.pop();
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
    p.KLargestElements();
}