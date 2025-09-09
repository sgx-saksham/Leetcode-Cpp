#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "SAksham Gupta ?? %% && ";
    string another = s;
    vector<int> frequency;
    vector<char> characters;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        another[i] = tolower(another[i]);
        if (another[i] >= 97 && another[i] <= 122)
            m[another[i]]++;
    }
    for (auto i : m)
    {
        characters.push_back(i.first);
        frequency.push_back(i.second);
    }

    reverse(characters.begin(), characters.end());
    reverse(frequency.begin(), frequency.end());
    for (int i = 0; i < characters.size(); i++)
    {
        cout << characters[i] << " " << frequency[i] << endl;
    }
}
