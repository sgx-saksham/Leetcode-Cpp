/*
    Q5 - Check if ith Bit is Set or Not for a given number
    2 13
*/
#include <bits/stdc++.h>
using namespace std;

bool bitSetOrNot(int i, int n)
{
    int mask = 1 << i;
    return ((mask)&n);
}

int main()
{
    int i, n;
    cin >> i >> n;
    cout << bitSetOrNot(i, n);
}