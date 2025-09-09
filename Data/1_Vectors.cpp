/*
    SGX is on the Code
*/
// '1_Vectors.cpp'
/*
1
10
1 2 5 3 4 3 4 3 8 6
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Add typedefs or macros here
void Delete_Vec(vector<int> &vec)
{
    for (auto &&i : vec)
    {
        vec.pop_back();
    }
}
void Print_vec(vector<int> &vec)
{
    for (auto &&i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
void Scan_vec(vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        int m;
        cin >> m;
        vec.push_back(m);
    }
}
// Solving functions
void Solve()
{
    int n;
    cin >> n;
    vector<int> v, d, o;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    Print_vec(v);
    sort(v.begin(), v.end());
    Print_vec(v);
    random_shuffle(v.begin(), v.end());
    Print_vec(v);
    sort(v.begin(), v.end());
    d = v;
    v.erase(unique(v.begin(), v.end()), v.end());
    Print_vec(v);
    cout << "v.begin: " << *v.begin() << endl;
    cout << "v.rbegin: " << *v.rbegin() << endl;
    cout << "v.end: " << *(v.end() + 2) << endl;
    cout << "v.rend: " << *(v.rend() - 1) << endl;
    cout << "v.front: " << v.front() << endl;
    cout << "v.back: " << v.back() << endl;
    Print_vec(v);
    sort(v.rbegin(), v.rend());
    Print_vec(v);
    sort(v.begin(), v.end());
    Print_vec(v);
    auto a = lower_bound(v.begin(), v.end(), 5);
    auto b = upper_bound(v.begin(), v.end(), 5);
    cout << "Lower Bound : " << *(a - 1) << "\n";
    cout << "Upper Bound : " << *b << "\n";
    Print_vec(v);
    d.push_back(9);
    Print_vec(d);
    set_intersection(begin(d), end(d), begin(v), end(v), inserter(o, end(o)));
    Print_vec(o);
    Delete_Vec(o);
    set_difference(begin(d), end(d), begin(v), end(v), inserter(o, end(o)));
    Print_vec(o);
    Delete_Vec(o);
    set_union(begin(d), end(d), begin(v), end(v), inserter(o, end(o)));
    Print_vec(o);
    Delete_Vec(o);
    set_symmetric_difference(begin(d), end(d), begin(v), end(v), inserter(o, end(o)));
    Print_vec(o);
    Delete_Vec(o);
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t-- > 0)
    {
        Solve();
    }

    return 0;
}