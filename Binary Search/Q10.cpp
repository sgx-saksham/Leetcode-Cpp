/*
Q10 - Find the position of an element in infinite sorted array
9
1 2 3 4 8 10 10 12 19
19
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n, t, start, end;
    vector<int> v;
    void getStart()
    {
        int low = 0, high = 1;
        while (t > v[high])
        {
            low = high;
            high *= 2;
        }
        start = low;
        end = high;
        cout << "start : " << start << "\nEnd: " << end << endl;
    }

    int infiniteSearch()
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
    b.getStart();
    cout << "Ans : " << b.infiniteSearch() << endl;
}