#include <bits/stdc++.h>
using namespace std;

void isValidToken(string t)
{
    int state = 0;
    for (auto i = 0; i < t.length(); i++)
    {
        switch (state)
        {
        case 0:
            state = t[i] == 'a' ? 1 : 0;
            break;
        case 1:
            state = t[i] == 'a' ? 1 : 2;
            break;
        case 2:
            state = t[i] == 'a' ? 1 : 3;
            break;
        case 3:
            state = t[i] == 'a' ? 1 : 0;
            break;
        default:
            state = 0;
        }
    }
    if (state == 3)
        cout << "Token is valid\n";
    else
        cout << "Token is invalid\n";
}

int main()
{
    string token = "aabababb";
    isValidToken(token);
    return 0;
}