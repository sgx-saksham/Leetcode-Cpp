#include <bits/stdc++.h>
using namespace std;
class StringVector
{
public:
    vector<string> v;
    void ADD(string s)
    {
        v.push_back(s);
    }
    void REMOVE(string s)
    {
        for (int i = 0; i < v.size(); i++)
            if (v[i] == s)
                v.erase(v.begin() + i);
    }
    void INSERT(string s, string t)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == t)
            {
                v.insert(v.begin() + i, s);
                break;
            }
        }
    }
    void SHOW()
    {
        if (v.empty())
        {
            cout << "0\n";
            return;
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
};

vector<string> Solver(string text, int Q, vector<string> queries)
{
    string temp;
    map<string, string> m;
    vector<string> ans;
    int n = queries.size();
    for (int i = 0; i < n; i++)
    {
        temp = queries[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        stringstream ss;
        ss.str("");
        ss << temp;
    }
}

// Solving functions
void Solve()
{
    StringVector S;
    string s;
    vector<vector<string>> vi;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string l;
        vector<string> v;
        while (ss >> l)
            v.push_back(l);
        vi.push_back(v);
    }
    for (int i = 1; i < vi.size(); i++)
    {
        if (vi[i][0] == "ADD")
            S.ADD(vi[i][1]);
        else if (vi[i][0] == "INSERT")
            S.INSERT(vi[i][1], vi[i][2]);
        else if (vi[i][0] == "REMOVE")
            S.REMOVE(vi[i][1]);
        else if (vi[i][0] == "SHOW")
            S.SHOW();
        else
        {
            cout << "0\n";
            break;
        }
    }
};
