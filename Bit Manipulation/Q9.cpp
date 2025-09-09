/*
Q9 - Clear The last set bit of a number
10
*/
#include <bits/stdc++.h>
using namespace std;

int clearTheLastSetBit(int n)
{
    return (n & n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << clearTheLastSetBit(n);
}