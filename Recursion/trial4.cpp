#include <iostream>
using namespace std;
int gcd_s(int a, int b)
{
    return b == 0 ? a : gcd_s(b, a % b);
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);

    // int a, b;
    // cin >> a >> b;
    // cout << gcd_s(a, b);
    cout << "Saksham";
}