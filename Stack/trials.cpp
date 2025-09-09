/*
    SGX is on the Code
*/
// 'trials.cpp'
/*
Test Cases for the code
*/

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimizations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
class superiorFunctions
{
public:
    int charToInt(char c)
    {
        if (isdigit(c))
            return c - '0';
        else
            return -1;
    }

    vector<int> StringToIntVector(string s)
    {
        vector<int> v;
        int n = 0;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i - 1] == '-')
                flag = false;
            while (isdigit(s[i]))
            {
                n *= 10;
                n += (s[i] - '0');
                i++;
                if (isdigit(s[i]) == false && flag == true)
                {
                    v.push_back(n);
                    n = 0;
                }
                else if (isdigit(s[i]) == false && flag == false)
                {
                    n *= -1;
                    v.push_back(n);
                    flag = true;
                    n = 0;
                }
            }
        }
        return v;
    }

    vector<string> vectorOfStrings(string s)
    {
        vector<string> v;
        for (int i = 0; i < s.length(); i++)
        {
            string p = "";
            if (s[i + 1] == ' ')
            {
                v.push_back(p);
                p = "";
            }
            else
            {
                p.push_back(s[i]);
            }
        }
        return v;
    }
};

class InputOutput
{
public:
    string inputString()
    {
        string s;
        getline(cin, s);
        return s;
    }
    vector<int> inputStaticVector()
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        return v;
    }
    vector<int> inputDynamicVector()
    {
        int t;
        vector<int> v;
        while (cin >> t)
            v.push_back(t);
        return v;
    }
    void PrintVector(vector<int> v)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
};

class Stack
{
public:
    vector<int> v, ss;
    void push(int n)
    {
        v.push_back(n);
    }
    void pop()
    {
        v.pop_back();
    }
    int minimum()
    {
        return *min_element(v.begin(), v.end());
    }
    int maximum()
    {
        return *max_element(v.begin(), v.end());
    }
    void printStack()
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
};

// Solving functions
vector<int> finalPrices(vector<int> &prices)
{
    vector<int> v;
    stack<int> st;
    int n = prices.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            v.push_back(prices[i]);
        else if (st.top() > prices[i])
        {
            while (!st.empty() && st.top() > prices[i])
                st.pop();
            if (st.empty())
                v.push_back(prices[i]);
            else
                v.push_back(prices[i] - st.top());
        }
        else
            v.push_back(prices[i] - st.top());

        st.push(prices[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
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