/*
    SGX is on the Code
*/
// 'Name.cpp'
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string spaceToUnderscore(string text)
{
    replace(text.begin(), text.end(), ' ', '_');
    string full = text + ".cpp";
    return full;
}

// Main Function / Driver Code
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    string str;
    getline(cin, str);

    string s = spaceToUnderscore(str);
    int n = s.length();
    char char_array[n + 1];
    strcpy(char_array, s.c_str());

    freopen(char_array, "w", stdout);

    return 0;
}