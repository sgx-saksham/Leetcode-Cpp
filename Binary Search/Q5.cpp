/*
Q5 - No. of times the array is rotated
8
11 12 15 18 2 5 6 8
*/

#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n;
    vector<int> v;
    int CountRotation()
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            int next = (mid + 1) % n, prev = (mid + n - 1) % n;
            if (v[mid] <= v[prev] && v[mid] <= v[next])
                return (n - mid);
            else if (v[mid] <= v[end])
                end = mid - 1;
            else if (v[mid] >= v[0])
                start = mid + 1;
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
    cout << b.CountRotation() << endl;
}