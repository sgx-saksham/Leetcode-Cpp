/*
    SGX is on the Code
*/
// '00_Trials.cpp'
/*
1
123
456
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

// Solving functions
void Solve()
{
    string s, d, o, p;
    stringstream ss;
    cin >> s >> d;
    int sl = s.length(), dl = d.length(), siz, carry = 0, dt = dl - 1, st = sl - 1;
    vector<int> sv, dv, a;
    vector<vector<int>> v;
    for (int i = 0; i < sl; i++)
    {
        o = s[i];
        sv.push_back(stoi(o));
    }
    for (int i = 0; i < dl; i++)
    {
        o = d[i];
        dv.push_back(stoi(o));
    }
    // multiplication
    for (int i = dt; i >= 0; i--)
    {
        int k = dt - i, carry = 0, temp;
        vector<int> t1;
        for (int j = st; j >= 0; j--)
        {

            temp = (dv[i] * sv[j]) + carry;
            if (i == 0 && j == 0 || j == 0)
            {
                int t = temp;
                if (t >= 10)
                {
                    while (t >= 10)
                    {
                        t1.push_back(t % 10);
                        t1.push_back(t / 10);
                        t /= 10;
                    }
                }
                else
                    t1.push_back(temp);
            }
            else
            {
                if (temp >= 10)
                    carry = temp / 10;
                t1.push_back(temp % 10);
            }
        }
        for (int j = 0; j < i; j++)
        {
            t1.push_back(0);
        }
        reverse(t1.begin(), t1.end());
        for (int j = 0; j < k; j++)
        {
            t1.push_back(0);
        }
        siz = t1.size();
        v.push_back(t1);
    }
    // addition of the columns
    for (int i = siz - 1; i >= 0; i--)
    {
        int k = dt, temp = 0;
        for (int j = dl - 1; j >= 0; j--)
        {
            temp += v[j][i];
        }
        temp += carry;
        if (i != 0)
        {
            if (temp >= 10)
                carry = temp / 10;
            a.push_back(temp % 10);
        }
        else
        {
            if (temp != 9)
                temp -= 1;
            a.push_back(temp);
        }
    }
    reverse(a.begin(), a.end());
    for (auto it = a.begin(); it != a.end(); it++)
        ss << *it;
    p = ss.str();
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}