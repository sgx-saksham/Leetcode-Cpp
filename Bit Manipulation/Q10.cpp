/*
Q10 - Count the set bits of a number
11
*/
#include <bits/stdc++.h>
using namespace std;

int countTheSetBitsOfNum(int n)
{
    int c = 0;
    // optimised approach
    while (n != 0)
    {
        n &= n - 1;
        c++;
    }

    // Less Optimised Approach
    // while (n != 0)
    // {
    //     if (n & 1 == 1)
    //         c++;
    //     n >>= 1;
    // }

    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << countTheSetBitsOfNum(n);
}