/*
Q3 - 1st and Last occurrence of  an element in a sorted array
8
2 10 10 10 10 10 18 20
10
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t;
    vector<int> v;
    int B_Search_FirstOccurrence()
    {
        int start = 0, end = n - 1, mid, res = -1;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            if (t == v[mid])
            {
                res = mid;
                end = mid - 1;
            }
            else if (t < v[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return res;
    }
    int B_Search_LastOccurrence()
    {
        int start = 0, end = n - 1, mid, res = -1;
        while (start <= end)
        {
            mid = start + ((end - start) / 2);
            if (t == v[mid])
            {
                res = mid;
                start = mid + 1;
            }
            else if (t < v[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return res;
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
    cout << "First: " << b.B_Search_FirstOccurrence() << endl;
    cout << "Last: " << b.B_Search_LastOccurrence() << endl;
}