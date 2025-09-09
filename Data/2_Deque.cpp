/*
    SGX is on the Code
*/
// '2_Deque.cpp'
/*
Test Cases for the code
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here
void Print_deque(deque<int> d)
{
    for (auto &&i : d)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Solving functions
void Solve()
{
    int n;
    cin >> n;
    deque<int> d, m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        d.push_front(temp);
    }
    Print_deque(d);
    sort(d.begin(), d.end());
    Print_deque(d);
    reverse(d.begin(), d.end());
    Print_deque(d);
    random_shuffle(d.begin(), d.end());
    Print_deque(d);
    m = d;
    sort(m.begin(), m.end());
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    Print_deque(d);
    d.push_back(4);
    d.push_back(3);
    d.push_back(3);
    Print_deque(d);
    sort(d.begin(), d.end());
    Print_deque(d);
    d.pop_back();
    d.pop_front();
    d.pop_back();
    Print_deque(d);
    d.erase(unique(d.begin(), d.end()), d.end());
    Print_deque(d);
    d.push_front(1);
    d.push_back(6);
    d.push_back(8);
    Print_deque(d);
};

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    long t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}