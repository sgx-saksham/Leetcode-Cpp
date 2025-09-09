#include <bits/stdc++.h>
using namespace std;

vector<string> Contact(string s)
{
    vector<string> v;
    string p = "\"";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            p += "\"";
            v.push_back(p);
            p = "\"";
        }
        else
            p += s[i];
    }
    p += "\"";
    v.push_back(p);
    return v;
}

void Solve(vector<string> v)
{
    cout << "var contactName = document.getElementById(\"name\");\nvar contactEmail = document.getElementById(\"email\");\nvar contactMobile = document.getElementById(\"number\");\nvar DOB = document.getElementById(\"date\");\n\n";
    for (int i = 1; i < v.size(); i++)
    {
        vector<string> t = Contact(v[i]);

        string Name = t[0], Email = t[1], Mobile = t[2], DOB = t[3];

        cout << "contactName.value = " << Name << ";\n";
        cout << "contactEmail.value = " << Email << ";\n";
        cout << "contactMobile.value = " << Mobile << ";\n";
        cout << "DOB.value = " << DOB << ";\n\n";
        cout << "document.getElementById(\"submitButton\").click();\ndocument.getElementById(\"resetButton\").click();\n\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.csv", "r", stdin);
    freopen("Script.js", "w", stdout);
    string s;
    vector<string> v;
    while (getline(cin, s))
        v.push_back(s);
    Solve(v);
}