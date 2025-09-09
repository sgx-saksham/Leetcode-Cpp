#include <bits/stdc++.h>

// Type Names
#define vv vector<vector<string>>
#define pp pair<int, int>
// Type Names Ends

using namespace std;

vector<string> Delimit(string s)
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
    return a;
}

void PrintBoard(vv matrix)
{
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Reset(string s1, string s2)
{
    vector<string> D1 = Delimit(s1);
    vector<string> D2 = Delimit(s2);
    vv matrix(5, vector<string>(5, "--"));
    for (int i = 0; i < 5; i++)
    {
        matrix[0][i] = "B-" + D2[i];
        matrix[4][i] = "A-" + D1[i];
    }
    int a = 5, b = 5;
    PrintBoard(matrix);
}

// Completing L F D R
void L_move();
void F_move();
void D_move();
void R_move();

int main()
{
    cout << "\tWelcome To the Game\n";
    cout << "This is a Multiplayer Game so Kindly Provide with Inputs for both the player\n";
    cout << "Player 1 Inputs : ";
    string p1, p2;
    getline(cin, p1);
    cout << "Thats a strong unit\n";
    cout << "Now Turn for Player 2 \n";
    cout << "Player 2 Inputs : ";
    getline(cin, p2);
    cout << "Looks Like a tough Competition\n";
    Reset(p1, p2);
    // bool A = true, B = true;
    // while (A != false || B != false)
    // {
    // }
    return 0;
}