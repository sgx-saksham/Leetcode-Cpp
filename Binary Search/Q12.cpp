/*
Q12 - Minimum difference element in a sorted array
9
1 2 3 4 8 10 10 12 19
15
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t;
    vector<int> v;

    int minDiff()
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            if (t == v[mid])
                return v[mid];
            else if (t < v[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        int ms = abs(v[start] - t), me = abs(v[end] - t);
        if (ms < me)
            return v[start];
        else
            return v[end];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    B_Search b;
    cin >> b.n;
    for (int i = 0; i < b.n; i++)
    {
        int x;
        cin >> x;
        b.v.push_back(x);
    }
    cin >> b.t;
    cout << "Min : " << b.minDiff() << endl;
}