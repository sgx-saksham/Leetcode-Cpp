#include <bits/stdc++.h>
using namespace std;
string hundred = "Hundred", thousand = "Thousand", million = "Million", space = " ", zero = "Zero";
vector<string> numbers = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> units = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> number = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string TwoDigit(string s)
{
    string ans = "", fir, sec;
    fir = s[0];
    sec = s[1];
    if (s[0] == '0')
    {
        return units[stoi(sec)];
    }
    if (s[0] == '1')
    {
        return number[stoi(sec)];
    }
    else if (s[1] == '0')
    {
        return numbers[stoi(fir)];
    }
    else
    {
        ans += units[stoi(fir)];
        ans += space;
        ans += numbers[stoi(sec)];
    }
    return ans;
}
string GetHundred(string s)
{
    string ans = "", o = "", f;
    f = s[0];
    o += s[1];
    o += s[2];
    if (s[0] != '0')
    {
        ans += numbers[stoi(f)];
        ans += space;
        ans += hundred;
        ans += space;
        ans += TwoDigit(o);
    }
    else
    {
        ans += TwoDigit(o);
    }
    return ans;
}
string numberToWords(int num)
{
    if (num == 0)
        return zero;
    string s = to_string(num), zeros = "", ans = "", mill = "", hund = "", thou = "";
    int add_zero = 9 - s.size();
    for (int i = 1; i <= add_zero; i++)
        zeros += "0";
    s = zeros + s;
    mill += s[0];
    mill += s[1];
    mill += s[2];
    thou += s[3];
    thou += s[4];
    thou += s[5];
    hund += s[6];
    hund += s[7];
    hund += s[8];
    int i_mill = stoi(mill), i_thou = stoi(thou), i_hund = stoi(hund);

    if (i_mill > 0)
    {
        ans += GetHundred(mill) + space + million + space;
        if (i_thou > 0)
        {
            ans += GetHundred(thou) + space + thousand + space;
            if (i_hund > 0)
                ans += GetHundred(hund);
        }
        else
        {
            if (i_hund > 0)
                ans += GetHundred(hund);
        }
    }
    else
    {
        if (i_thou > 0)
        {
            ans += GetHundred(thou) + space + thousand + space;
            if (i_hund > 0)
                ans += GetHundred(hund);
        }
        else
        {
            if (i_hund > 0)
                ans += GetHundred(hund);
        }
    }
    return ans;
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
    cout << numberToWords(t) << endl;

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}