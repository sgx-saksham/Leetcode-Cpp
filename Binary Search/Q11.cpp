/*
Q11 - Index of the first 1 in the infinite binary sorted array
9
0 0 0 0 1 1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t = 1;
    vector<int> v;
    int B_Search_FirstOccurrence(int start, int end)
    {
        int mid, res = -1;
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
    int firstIndex()
    {
        int low = 0, high = 1;
        while (t > v[high])
        {
            low = high;
            high *= 2;
        }
        return B_Search_FirstOccurrence(low, high);
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
    cout << "First : " << b.firstIndex() << endl;
}