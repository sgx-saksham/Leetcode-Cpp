#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // create a vector of size n and initialize it from 0 to n and then print the vector
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    for (auto &&i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}