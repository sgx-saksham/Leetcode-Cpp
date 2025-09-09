/*
    SGX is on the Code
*/
// '0_Trials.cpp'
/*
1
2
1 2
2
3 4
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> v;
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = 0; i < n1; i++)
        v.push_back(nums1[i]);
    for (int i = 0; i < n1; i++)
        v.push_back(nums2[i]);
    sort(v.begin(), v.end());
    int m = v.size();
    int d = (double)v[(m / 2) - 1];
    int m1 = v[(m / 2) - 1], m2 = v[m / 2];
    double o = (double)(m1 + m2) / 2;
    if (m % 2 == 0)
        return o;
    else
        return d;
}
// Solving functions

int removeElement(vector<int> &nums, int val)
{
    vector<int>::iterator i;
    i = remove(nums.begin(), nums.end(), val);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    nums.shrink_to_fit();
    return nums.size();
}

string getPermutation(int n, int k)
{
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    for (int i = 1; i <= k; i++)
        next_permutation(v.begin(), v.end());
    string s;
    stringstream ss;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
        {
            ss << " ";
        }
        ss << *it;
    }
    s = ss.str();
    return s;
}

vector<int> plusOne(vector<int> &digits)
{
    // cout << "Har Dhadhkte Pathar ko log DIL samajhte hai\nUmre beet jaati hai DIL ko DIL banane mai\n";
    string s, o;
    stringstream ss, sn;
    for (auto it = digits.begin(); it != digits.end(); it++)
        ss << *it;
    s = ss.str();
    long long n = stoll(s);
    n++;
    sn << n;
    sn >> s;
    digits.clear();
    for (int i = 0; i < s.length(); i++)
    {
        o = s[i];
        int n = stoi(o);
        digits.push_back(n);
    }
    return digits;
}

void Solve()
{
    string s = "12";
    int n = s[1] - '0';
    cout << n;
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