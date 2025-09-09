/*
Q6 - find an element in rotated sorted array
8
11 12 15 18 2 5 6 8
12
*/

#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t;
    vector<int> v;
    int MinElement()
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            int next = (mid + 1) % n, prev = (mid + n - 1) % n;
            if (v[mid] <= v[prev] && v[mid] <= v[next])
                return (mid);
            else if (v[mid] <= v[end])
                end = mid - 1;
            else if (v[mid] >= v[start])
                start = mid + 1;
        }
        return 0;
    }
    int __B_Search(int start, int end)
    {
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (t == v[mid])
                return mid;
            else if (t < v[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
    int findElement()
    {
        int ind = MinElement();
        int left = __B_Search(0, ind - 1);
        int right = __B_Search(ind, n - 1);
        if (left == -1)
            return right;
        else
            return left;
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
    cout << b.findElement() << endl;
}