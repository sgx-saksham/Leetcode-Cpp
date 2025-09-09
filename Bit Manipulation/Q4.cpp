/*
Q4 - Give the XOR value from L to R
5 9
*/

#include <bits/stdc++.h>
using namespace std;

int XORtillN(int n)
{
    int k = n % 4;
    if (k == 1)
        return 1;
    if (k == 2)
        return n + 1;
    if (k == 3)
        return 0;
    return n;
}

int XorFromLtoR(int l, int r)
{
    return XORtillN(l - 1) ^ XORtillN(r);
}

int main()
{
    int l, r;
    cin >> l >> r;
    cout << XorFromLtoR(l, r);
}