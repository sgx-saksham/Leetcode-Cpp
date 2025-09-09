/*
Q13 - Bitonic array max element
7
1 3 8 12 4 2 1
*/

#include <bits/stdc++.h>
using namespace std;

class BSearch
{
public:
    int n;
    vector<int> v;
    int maxElement()
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid > 0 && mid < n - 1)
            {
                if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1])
                    return mid;
                else if (v[mid] < v[mid + 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else if (mid == 0)
            {
                if (v[0] > v[1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == n - 1)
            {
                if (v[n - 1] > v[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
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

    BSearch b;
    cin >> b.n;
    for (int i = 0; i < b.n; i++)
    {
        int x;
        cin >> x;
        b.v.push_back(x);
    }
    cout << b.maxElement();
}