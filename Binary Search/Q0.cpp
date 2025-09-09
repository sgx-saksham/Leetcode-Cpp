/*
10
10 9 8 7 6 5 4 3 2 1
3
-------------------
10
1 2 3 4 5 6 7 8 9 10
6
*/

#include <bits/stdc++.h>
using namespace std;

int B_Search_Desc(int n, int t, vector<int> v)
{

    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (t == v[mid])
            return mid;
        else if (t < v[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int B_Search_Asc(int n, int t, vector<int> v)
{

    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (t == v[mid])
            return mid;
        else if (t < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> t;
    cout << B_Search_Asc(n, t, v) << endl;
}