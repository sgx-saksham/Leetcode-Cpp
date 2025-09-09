/*
Q7 - Searching in nearly sorted array
5
5 10 30 20 40
30
*/

#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t;
    vector<int> v;
    int SearchInNearlySortedArray()
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            int next = (mid + 1) % n, prev = (mid + n - 1) % n;
            if (t == v[mid])
                return mid;
            if (mid - 1 >= start && v[mid - 1] == t)
                return mid - 1;
            if (mid + 1 <= end && v[mid + 1] == t)
                return mid + 1;
            else if (v[mid] <= v[end])
                end = mid - 2;
            else if (v[mid] >= v[0])
                start = mid + 2;
        }
        return 0;
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
    cout << b.SearchInNearlySortedArray() << endl;
}