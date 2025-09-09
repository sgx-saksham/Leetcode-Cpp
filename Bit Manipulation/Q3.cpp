/*
Q3 - Give the XOR value from 1 to N
6
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

int main()
{
    int n;
    cin >> n;
    cout << XORtillN(n) << endl;
}