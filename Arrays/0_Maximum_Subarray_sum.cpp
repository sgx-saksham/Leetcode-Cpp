/*
    SGX is on the Code
*/
// '0_Maximum_Subarray_sum.cpp'
/*
1
8
-1 2 4 -3 5 2 -5 2
*/

#include <bits/stdc++.h>
using namespace std;

// Add typedefs or macros here

// Solving functions
void O_of_n_3(int a[], int n)
{
    cout << "O(n)3\n";
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int s = 0;
            // cout << "a: ";
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
            // cout << "s: ";
            for (int k = i; k <= j; k++)
            {
                s += a[k];
                cout << s << " ";
            }
            b = max(b, s);
            cout << endl;
        }
    }
    cout << b << endl;
}

void O_of_n_2(int a[], int n)
{
    int b = 0;
    cout << "O(n)2\n";
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        // cout << "a: ";
        for (int j = i; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
        // cout << "s: ";
        for (int j = i; j < n; j++)
        {
            s += a[j];
            cout << s << " ";
            b = max(b, s);
        }
        cout << endl;
    }
    cout << b << endl;
}

void O_of_n(int a[], int n)
{
    cout << "O(n)\n";
    int b = a[0], s = 0, p[n];
    // cout << "a: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // cout << "s: ";
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] + s << " ";
        p[i] = a[i] + s;
        s = max(a[i], a[i] + s);
        // cout << s << " ";
        b = max(b, s);
        cout << b << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    cout << b << endl;
}
void Solve()
{
    int n;
    cin >> n;
    int a[n], sum[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a[i] = temp;
        // a[i] = abs(temp);
    }
    // O_of_n_3(a, n);
    // O_of_n_2(a, n);
    O_of_n(a, n);

    // for (int i = 0; i < n; i++)
    // {
    //     sum[i] = a[i];
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         sum[i] += a[j];
    //     }
    // }
    // for (auto &&i : a)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : sum)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
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