/*
Q8 - Clear The ith bit of a number
1 10
*/

#include <bits/stdc++.h>
using namespace std;

int clearTheIthBit(int i, int n)
{
    int mask = ~(1 << i);
    return (mask & n);
}

int main()
{
    int i, n;
    cin >> i >> n;
    cout << clearTheIthBit(i, n);
}