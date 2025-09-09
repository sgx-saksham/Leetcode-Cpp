#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Solve(int n, vector<vector<string>> a, string d, string val)
{
    vector<vector<string>> ans;
    string ban, ahfn, ahln, rmn, bc;
    ban = "bank_account_number";
    ahfn = "account_holder_first_name";
    ahln = "account_holder_last_name";
    rmn = "registered_mobile_number";
    bc = "branch_code";
    int get_num;
    if (d == ban)
        get_num = 0;
    else if (d == ahfn)
        get_num = 1;
    else if (d == ahln)
        get_num = 2;
    else if (d == rmn)
        get_num = 3;
    else if (d == bc)
        get_num = 4;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i][get_num] == val)
            ans.push_back(a[i]);
    }
    return ans;
}

string solve_1(long long n)
{
    // 0-9 : 0-9
    // 10-35: A-Z
    // 36-61: a-z
    // 24523 -> 6NX
    stack<char> stack;
    int i, base10;
    char base62;
    string base62_full;
    for (i = n; i > 0; i /= 62)
    {
        base10 = i % 62;
        if (base10 >= 0 && base10 < 10)
            base62 = base10 + 48;
        else if (base10 >= 10 && base10 < 36)
            base62 = base10 - 10 + 65;
        else
            base62 = base10 - 36 + 97;
        stack.push(base62);
    }
    while (!stack.empty())
    {
        base62_full.push_back(stack.top());
        stack.pop();
    }
    return base62_full;
}

string reverseWords(string s)
{
    vector<string> a;
    string o;
    int l = s.length();
    char q[l], p[] = " ";
    strcpy(q, s.c_str());
    char *token = strtok(q, p);
    while (token)
    {
        o = token;
        a.push_back(o);
        token = strtok(NULL, p);
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return o;
}
void Comb(int i, int t, vector<int> v, vector<int> f, vector<vector<int>> &vi)
{
    if (i == v.size())
    {
        if (t == 0)
        {
            vi.push_back(f);
            return;
        }
        else
            return;
    }
    if (v[i] <= t)
    {
        f.push_back(v[i]);
        Comb(i, t - v[i], v, f, vi);
        f.pop_back();
    }
    Comb(i + 1, t, v, f, vi);
}

void Comb1(int i, int t, int c, vector<int> v, vector<int> &f)
{
    if (i == v.size())
    {
        if (t == 0)
        {
            f.push_back(c);
            return;
        }
        else
            return;
    }
    if (v[i] <= t)
    {
        c++;
        Comb1(i, t - v[i], c, v, f);
        c--;
    }
    Comb1(i + 1, t, c, v, f);
}

int Combination(int i, int t, int c, vector<int> v)
{

    c++;
    int take = Combination(i, t - v[i], c, v);
    c--;
    int notTake = Combination(i + 1, t - v[i], c, v);

    int mn = min(take, notTake);
}

void Perfect()
{
    int n, t = 0;
    cin >> n;
    vector<vector<int>> vi;
    vector<int> v, f;
    for (int i = 1; t <= n; i++)
    {
        t = i * i;
        v.push_back(t);
    }
    v.pop_back();
    // Comb(0, n, v, f, vi);
    Comb1(0, n, 0, v, f);
    for (auto i : f)
        cout << i << " ";
    // for (auto i : vi)
    // {
    //     for (auto &&j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Perfect();
}