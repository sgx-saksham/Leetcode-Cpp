/*
Q8 - Floor / ceil of an element
9
1 2 3 4 8 10 10 12 19
11
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t;
    vector<int> v;
    int floor()
    {
        int start = 0, end = n - 1, mid, res = 0;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (v[mid] == t)
                return t;
            else if (v[mid] < t)
            {
                res = v[mid];
                start = mid + 1;
            }
            else if (v[mid] > t)
                end = mid - 1;
        }
        return res;
    }
    int ceil()
    {
        int start = 0, end = n - 1, mid, res = 0;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (v[mid] == t)
                return t;
            else if (v[mid] > t)
            {
                res = v[mid];
                end = mid - 1;
            }
            else if (v[mid] < t)
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
    cout << "floor : " << b.floor() << endl;
    cout << "ceil : " << b.ceil() << endl;
}