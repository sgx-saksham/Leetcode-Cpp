/*
Q9 - Next Letter Alphabetically
4
a c f h
f
*/
#include <bits/stdc++.h>
using namespace std;

class B_Search
{
public:
    int n;
    vector<char> v;
    char c;
    char ceil()
    {
        int start = 0, end = n - 1, mid;
        char res = '0';
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (v[mid] == c)
                start = mid + 1;
            else if (v[mid] > c)
            {
                res = v[mid];
                end = mid - 1;
            }
            else if (v[mid] < c)
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
        char x;
        cin >> x;
        b.v.push_back(x);
    }
    cin >> b.c;
    cout << "ceil : " << b.ceil() << endl;
}