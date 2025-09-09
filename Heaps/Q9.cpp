/*
Q9 - Sum of Elements between k1 smallest and k2 smallest numbers
6
1 3 12 5 15 11
3 6
*/
#include <bits/stdc++.h>
using namespace std;

class PQ
{
public:
    int n, k1, k2;
    vector<int> v;
    int KthElement(int k)
    {
        priority_queue<int> maxH;
        if (n < k)
            return -1;
        for (int i = 0; i < n; i++)
        {
            maxH.push(v[i]);
            if (maxH.size() > k)
                maxH.pop();
        }
        return maxH.top();
    }
    int Sum()
    {
        int e1 = KthElement(k1);
        int e2 = KthElement(k2), sum = 0;
        cout << e1 << " " << e2 << endl;
        for (auto i : v)
        {
            if (i > e1 && i < e2)
                sum += i;
        }
        return sum;
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
        int t;
        cin >> t;
        p.v.push_back(t);
    }
    int k1, k2;
    cin >> p.k1 >> p.k2;
    cout << p.Sum() << endl;
}