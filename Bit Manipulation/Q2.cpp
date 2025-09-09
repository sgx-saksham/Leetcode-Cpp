/*
Q2 - swap two Numbers
12 5
*/

#include <bits/stdc++.h>
using namespace std;

void swapByBitManipulation(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << "Before : \t" << n << " " << m << endl;
    swapByBitManipulation(n, m);
    cout << "After : \t" << n << " " << m << endl;
}