/*
Q7 - Set The ith bit of a number
1 8
*/
#include <bits/stdc++.h>
using namespace std;

int setTheIthBit(int i, int n)
{
    int mask = 1 << i;
    return (mask | n);
}

int main()
{
    int i, n;
    cin >> i >> n;
    cout << setTheIthBit(i, n);
}