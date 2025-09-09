/*
Q14 - Search in a Bitonic array
7
1 3 8 12 4 2 1
*/

#include <bits/stdc++.h>
using namespace std;

class BSearch
{
public:
    int n, t;
    vector<int> v;
    int Peak()
    {
        int start = 0, n = v.size(), end = n - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid > 0 && mid < n - 1)
            {
                if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1])
                    return mid;
                else if (v[mid - 1] > v[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
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
    int B_Search_Desc(int start, int end)
    {
        int mid;
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

    int B_Search_Asc(int start, int end)
    {
        int mid;
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
    int SearchBitonic()
    {
        int ind = Peak();
        int A = B_Search_Asc(0, ind - 1);
        int B = B_Search_Desc(ind, n - 1);
        if (A == -1)
            return B;
        else
            return A;
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
    cin >> b.t;
    cout << b.SearchBitonic();
}