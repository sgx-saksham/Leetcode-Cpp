/*
Q10 - Max Area of Histogram
MAH
7
6 2 5 4 5 1 6
*/

#include "stack_saksham.hpp"
using namespace std;

int MAH(vector<int> height, int n)
{
    vector<int> NSR = NSR_ind(height);
    vector<int> NSL = NSL_ind(height);
    vector<int> width(n), area(n);
    for (int i = 0; i < n; i++)
        width[i] = NSR[i] - NSL[i] - 1;
    for (int i = 0; i < n; i++)
        area[i] = height[i] * width[i];
    for (auto &&i : height)
        cout << i << "\t";
    cout << endl;
    for (auto &&i : width)
        cout << i << "\t";
    cout << endl;
    for (auto i : area)
        cout << i << "\t";
    cout << endl;
    return *max_element(area.begin(), area.end());
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << MAH(v, n);
}