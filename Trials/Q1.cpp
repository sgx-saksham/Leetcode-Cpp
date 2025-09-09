#include <bits/stdc++.h>
using namespace std;

void REMOVE(string &v, char s)
{
    if (v[0] == '<')
        v.erase(v.begin());
    if (v[v.size() - 1] == '>')
        v.erase(v.end() - 1);
    for (int i = 0; i < v.size(); i++)
        if (v[i] == s)
            v.erase(v.begin() + i);
}

void INSERT(string &v)
{
    string s = " ";
    char t = '=';
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == t)
        {
            // v.insert(v.begin() + i, ((char)32));
            v.insert(i, s);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    string s;
    vector<vector<string>> vi;
    while (getline(cin, s))
    {
        REMOVE(s, '=');
        stringstream ss(s);
        string l;
        vector<string> v;
        while (ss >> l)
            v.push_back(l);
        vi.push_back(v);
        for (auto i : v)
            cout << i << "\n";
        cout << "\n\n\n";
    }
}