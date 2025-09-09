/*
Q4 - K closest Numbers
5
5 6 7 8 9
3 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

class PQ
{
public:
    int n, k, x;
    vector<int> v;
    priority_queue<pair<int, int>> maxHeap;
    void Closest()
    {
        for (int i = 0; i < n; i++)
        {
            maxHeap.push({abs(v[i] - x), v[i]});
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
    cin >> p.k >> p.x;
    p.Closest();
}