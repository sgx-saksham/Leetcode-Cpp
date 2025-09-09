#include <bits/stdc++.h>
/*
Test cases
1 2 3  4  54
1 2 4
*/

using namespace std;

void permute(vector<int> v, int n, int f)
{
    int s;
}

void func(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<int> t = v;
    reverse(t.begin(), t.end());
    int n = v.size();
    int a[n + 1];
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i * a[i - 1];
    }
    int total = a[n];
    permute(v, n, total);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;
    string s, o;
    getline(cin, s);
    int l = s.length();
    char q[l], p[] = ",";
    // p is the delimiter for the strtok so keep the space or comma accordingly
    strcpy(q, s.c_str());
    char *token = strtok(q, p);
    while (token)
    {
        o = token;
        a.push_back(stoi(o));
        token = strtok(NULL, p);
    }
    // You get the vector a that will have the input stored element wise;
    func(a);
    cout << endl;
}