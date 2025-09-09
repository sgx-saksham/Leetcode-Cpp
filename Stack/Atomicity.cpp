#include <bits/stdc++.h>
using namespace std;

// ATOMICITY & DURABILITY at atomic level LLD

bool increment(int &ind, vector<int> &shadowCopy, char value)
{
    shadowCopy[ind]++;
    cout << "updates = ";
    for (auto iter : shadowCopy)
        cout << iter << " ";
    cout << endl;
    try
    {
        if (isdigit(value))
        {
            // natural disaster
            shadowCopy[ind]--;
            shadowCopy[ind] += (int)value - '0';
        }
        else
        {
            cout << "Error Encountered\n";
            throw(value);
        }
    }
    catch (char value)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> original = {1, 2};    // this vector stays consistent
    vector<int> *db = &original;      // db pointer to original db
    vector<int> shadowCopy(original); // this is making durable
    int ind = 1;
    char value = 'A';
    cin >> ind >> value;
    if (increment(ind, shadowCopy, value)) // atomicity checking
    {
        cout << "Success\nNew Transaction updated\n";
        *db = shadowCopy; // db pointer updated on success!
    }
    else
        cout << "Failed\nMove On Ma\n";
    for (auto iter : original)
        cout << iter << " "; // shows that transaction after the completion the system is durable;
    cout << endl;
}