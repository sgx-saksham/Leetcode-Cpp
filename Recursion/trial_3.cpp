#include <bitset>
#include <bits/stdc++.h>
using namespace std;

// void PrimeSieve(int n, int l)
// {
//     vector<int> prime(n + 1, 0);
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             for (int j = i * i; j <= n; j += i)
//                 prime[j] = 1;
//         }
//     }
//     for (int i = l; i <= n; i++)
//     {
//         if (prime[i] == 0)
//             cout << i << " ";
//     }
// }

// bool checkPrime(int n)
// {
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// void PrimeBrute(int l, int n)
// {
//     for (int i = l; i <= n; i++)
//     {
//         bool c = checkPrime(i);
//         if (c)
//             cout << i << " ";
//     }
// }

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    int temp, k = 2;
    vector<int> nums;
    while (cin >> temp)
        nums.push_back(temp);
    unordered_map<int, int> m;
    vector<pair<int, int>> p;
    vector<int> v, ele;
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;
    for (auto i : m)
        p.push_back(make_pair(i.second, i.first));
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    for (auto i : p)
        ele.push_back(i.second);
    for (int i = 0; i < k; i++)
        v.push_back(ele[i]);
    sort(v.begin(), v.end());

    for (auto &&i : v)
        cout << i << " ";
}