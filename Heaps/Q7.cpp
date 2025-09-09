/*
Q7 - K closest Points to Origin
4
1 3
-2 2
5 8
0 1
2
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
class PQ
{
public:
    int n, k;
    vector<pp> v;
    priority_queue<pp> maxH;
    void closestOrigin()
    {
        for (int i = 0; i < n; i++)
        {
            int sum = (v[i].first * v[i].first) + (v[i].second * v[i].second);
            maxH.push({sum, i});
            if (maxH.size() > k)
                maxH.pop();
        }
        while (maxH.size() > 0)
        {
            int i = maxH.top().second;
            cout << v[i].first << " " << v[i].second << endl;
            maxH.pop();
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

    PQ p;
    cin >> p.n;
    for (int i = 0; i < p.n; i++)
    {
        int a, b;
        cin >> a >> b;
        p.v.push_back({a, b});
    }
    cin >> p.k;
    p.closestOrigin();
}