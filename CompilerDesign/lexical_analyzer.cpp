#include <bits/stdc++.h>
using namespace std;

void lex(string expr, vector<string> &tokens)
{
    string identifier = "";
    for (auto i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '+' || expr[i] == '*' || expr[i] == '(' || expr[i] == ')' || expr[i] == ' ')
        {
            if (identifier != "")
            {
                tokens.push_back(identifier);
                identifier = "";
            }
            if (expr[i] != ' ')
            {
                string temp = "";
                temp += expr[i];
                tokens.push_back(temp);
            }
        }
        else
            identifier += expr[i];
    }
    if (identifier != "")
        tokens.push_back(identifier);
}

int main()
{
    // E ---> E + T | T
    // T ---> T * F | F
    // F ---> (E) | id

    string expr = "(a + 5) * b";
    vector<string> tokens;
    lex(expr, tokens);
    cout << "The tokens are:\n";
    for (auto t : tokens)
        cout << t << ", ";
    cout << endl;
    return 0;
}