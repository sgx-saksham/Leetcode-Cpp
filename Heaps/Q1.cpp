/*
Q1 - Kth smallest Element in array
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
    priority_queue<int> maxHeap;
    vector<int> v;
    int KthElement()
    {
        if (n < k)
            return -1;
        for (int i = 0; i < n; i++)
        {
            maxHeap.push(v[i]);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        return maxHeap.top();
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
    cout << p.KthElement() << endl;
}