/*
    SGX is on the Code
*/
// '2_Valid_Anagram.cpp'
/*
2
anagram
nagaram
rat
car
*/

#include <bits/stdc++.h>
using namespace std;

// Add typedefs or macros here
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s == t);
}

// Solving functions
void Solve()
{
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t) << endl;
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