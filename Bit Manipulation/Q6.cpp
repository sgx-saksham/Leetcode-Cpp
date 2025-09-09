/*
Q6 - Check whether number is a power of 2 or not;
8
*/
#include <bits/stdc++.h>
using namespace std;

bool powerOfTwo(int n)
{
    return (n & (n - 1));
}

int main()
{
    int n;
    cin >> n;
    if (powerOfTwo(n))
        cout << "Nope\n";
    else
        cout << "Yups\n";
}