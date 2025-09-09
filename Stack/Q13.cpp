/*
Q13 - Minimum Element in stack in extra space
2
18 19 21 15 16 p p 17 18
0 1 0 2 1 0 1 3 2 1 2 1
*/
#include <bits/stdc++.h>
using namespace std;

class StackVec
{
public:
    vector<int> v, ss;
    void push(int n)
    {
        v.push_back(n);
        if (ss.empty() || ss.back() > n)
            ss.push_back(n);
    }
    void pop()
    {
        if (v.empty())
            return;
        if (ss.back() == v.back())
            ss.pop_back();
        v.pop_back();
    }
    int minimum()
    {
        if (ss.empty())
            return -1;
        return ss.back();
    }
};

vector<string> StringToVectorString(string s)
{
    vector<string> v;
    string p = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            p += s[i];
        else
        {
            v.push_back(p);
            p = "";
        }
    }
    return v;
}
bool is_number(const string &s)
{
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}
void Solve()
{
    string s;
    getline(cin, s);
    vector<string> v = StringToVectorString(s);
    StackVec st;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "p")
            st.pop();
        else if (is_number(v[i]))
            st.push(stoi(v[i]));
    }
    cout << st.minimum() << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l;
    cin >> l;
    l++;
    while (l--)
    {
        Solve();
    }
}