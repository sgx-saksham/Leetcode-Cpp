#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int getWork(int n)
{
    string s = to_string(n);
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
        v.push_back((s[i]) - '0');
    int si = v.size() - 1;
    for (int i = si; i >= 0; i--)
    {
        if (v[i] != 9)
        {
            v[i]++;
            int res = 0;
            for (int j = 0; j < v.size(); j++)
                res = res * 10 + v[j];
            return res;
        }
    }
    return (n + pow(10, v[si]));
}

int Solve(int n)
{
    int current = 765;

    for (int i = 0; i < 18; i++)
    {
        current = getWork(current);
        cout << current << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Solve(n) << endl;
    }
}