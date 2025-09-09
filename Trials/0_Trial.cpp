/*
    SGX is on the Code
*/
// '0_Trial.cpp'
/*
Test Cases for the code
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <boost/multiprecision/float128.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace __gnu_pbds;
using namespace boost::multiprecision;
using namespace std;

// Add typedefs or macros here

// Solving functions
// long long fib(int n)
// {
//     long double f = sqrt(5);
//     long double a = pow((1 + f) / 2, n);
//     long double b = pow((1 - f) / 2, n);
//     long long s = (a - b) / f;
//     // int1024_t m = s;;
//     long long sum = fib(n + 2) - 1;
//     cout << sum << endl;
//     return s;
// }

// vector<int> plusOne(vector<int> &digits)
// {
//     vector<int> v;
//     int n = digits.size() - 1, i = n, carry = 0;
//     digits[n]++;
//     for (int i = n; i >= 0; i--)
//     {
//         digits[i] += carry;
//         if (digits[i] != 10)
//         {
//             v.push_back(digits[i]);
//             carry = 0;
//         }
//         else
//         {
//             carry = 1;
//             v.push_back(0);
//         }
//         if (i == 0 && digits[i] == 10 && carry == 1)
//             v.push_back(1);
//     }
//     reverse(v.begin(), v.end());
//     return v;
// }

// int pivotIndex(vector<int> &nums)
// {
//     int n = nums.size() - 1;
//     // vector<int> ls,rs;/
//     int ls[n + 1], rs[n + 1];
//     ls[0] = 0, rs[n] = 0;
//     for (int i = 1, j = n - 1; i <= n; i++, j--)
//     {
//         ls[i] += nums[i - 1];
//         rs[j] += nums[j + 1];
//         // if (ls[i] == rs[j])
//         //     return i;
//     }
//     for (auto &&i : ls)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     for (auto &&i : ls)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     return -1;
// }

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> v;
    vector<int> f = {1};
    v.push_back(f);
    if (numRows == 1)
        return v;
    vector<int> s = {1, 1};
    v.push_back(s);
    if (numRows == 2)
        return v;
    for (int i = 2; i < numRows; i++)
    {
        vector<int> y;
        y.push_back(1);
        for (int j = 1; j < i; j++)
        {
            int temp = (v[i - 1][j - 1] + v[i - 1][j]);
            y.push_back(temp);
        }
        y.push_back(1);
        v.push_back(y);
    }
    return v;
}

void Solve()
{
    int temp;
    cin >> temp;
    vector<int> nums = {1, 2, 3, 4, 5}, v = nums;
    int n = nums.size() - 1, a = n;
    while (a--)
    {
        vector<int> y;
        for (int i = 0; i < n; i++)
        {
            int temp = v[i] + v[i + 1];
            temp %= 10;
            y.push_back(temp);
        }
        v.clear();
        v = y;
    }
    int l = v[0];
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