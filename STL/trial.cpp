#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n, 0), v2(n);
    // Insert values 1 to 10
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int>::iterator new_end;
    remove_copy(v.begin(), v.end(), v2.begin(), 2);
    v2.resize(n);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    for (auto &&i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    // Prints [10 30 40 10]
    return 0;
}