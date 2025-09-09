/*
Q1 - check in an array which no. occurs only once among those elements which are twice
9
2 1 2 5 6 5 7 7 6
*/
#include <bits/stdc++.h>
using namespace std;

int getNumWithFreqOne(vector<int> v)
{
    int k = 0;
    for (int i = 0; i < v.size(); i++)
        k ^= v[i];
    return k;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << getNumWithFreqOne(v) << endl;
}