/*
Q17 - Allocate Minimum number of pages

4
10 20 30 40
2
*/

#include <bits/stdc++.h>
using namespace std;

class BSearch
{
public:
    int n, t;
    vector<int> v;

    void myApproach()
    {
        vector<int> mx, vec(t, 0);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += v[i];
            sum2 = 0;
            for (int j = i + 1; j < n; j++)
                sum2 += v[j];
            mx.push_back(max(sum1, sum2));
        }
        cout << *min_element(mx.begin(), mx.end());
    }
    bool isValid(int mx)
    {
        int student = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (sum > mx)
            {
                student++;
                sum = v[i];
            }
            if (student > t)
                return false;
        }

        return true;
    }
    void AV()
    {
        if (n < t)
        {
            cout << "-1\n";
            return;
        }

        int start = *max_element(v.begin(), v.end());
        int end = accumulate(v.begin(), v.end(), 0);
        int res = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isValid(mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        cout << start << endl;
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
    b.AV();
}