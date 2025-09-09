/*
    SGX is on the Code
*/
// '4_Queue.cpp'
/*
1
10
1 2 5 3 4 3 4 3 8 6
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Add typedefs or macros here

void Print_Queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
// Solving functions
void Solve()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    Print_Queue(q);
    cout << q.size() << "\n";

    cout << q.empty() << "\n";
    Print_Queue(q);
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