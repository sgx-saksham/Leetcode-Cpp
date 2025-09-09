/*
Q14 - Minimum Element in stack in O(1) space
2
18 19 p q 21 15 16 p p 17 p 18
0 p 1 0 p 2 1 0 p 1 3 2 1 2 1
*/
#include <bits/stdc++.h>
using namespace std;

class StackVecQ14
{
public:
    vector<int> v;
    int minimum;
    void push(int n)
    {
        if (v.empty())
        {
            v.push_back(n);
            minimum = min(minimum, n);
        }
        else
        {
            if (n >= minimum)
                v.push_back(n);
            else
            {
                v.push_back((2 * n) - minimum);
                minimum = n;
            }
        }
    }
    void pop()
    {
        if (v.empty())
            return;
        else
        {
            if (v.back() >= minimum)
                v.pop_back();
            else
            {
                minimum = (2 * minimum) - v.back();
                v.pop_back();
            }
        }
    }
    int getMin()
    {
        if (v.empty())
            return -1;
        return minimum;
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
    StackVecQ14 st;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "p")
            st.pop();
        else if (is_number(v[i]))
            st.push(stoi(v[i]));
    }
    cout << st.getMin() << endl;
}
int main()
{
    int n;
    cin >> n;
    n++;
    while (n--)
    {
        Solve();
    }
}