/*	Saksham is on the Code */
/* Virat + Anushka == "Virushka" */
// 'test.cpp'

#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<string> ans1, ans2;
    string temp = "";
    for (int i = 0; i < s1.length(); i++)
    {
        temp += s1[i];
        string temp2 = "";
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            temp2 += s2[j];
            string a = temp2, b = temp;
            reverse(a.begin(), a.end());
            b += a;
            ans1.push_back(b);
        }
    }
    temp = "";
    for (int i = 0; i < s2.length(); i++)
    {
        temp += s2[i];
        string temp2 = "";
        for (int j = s1.length() - 1; j >= 0; j--)
        {
            temp2 += s1[j];
            string a = temp2, b = temp;
            reverse(a.begin(), a.end());
            b += a;
            ans2.push_back(b);
        }
    }
    set<string> s;
    for (auto i : ans1)
        s.insert(i);
    for (auto i : ans2)
        s.insert(i);
    for (auto i : s)
        cout << i << "\n";
};

// Main Function / Driver Code
int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    Solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}