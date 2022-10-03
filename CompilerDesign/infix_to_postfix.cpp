#include <bits/stdc++.h>
using namespace std;

void lex(string expr, vector<string> &tokens)
{
    string identifier = "";
    tokens.push_back("(");
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
    tokens.push_back(")");
}

void infixToPostfix(vector<string> tokens, vector<string> &postfix)
{
    stack<string> operands;
    for (auto i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "(")
            operands.push(tokens[i]);
        else if (tokens[i] == "+")
        {
            while (operands.top() != "(")
            {
                string op = operands.top();
                operands.pop();
                postfix.push_back(op);
            }
            operands.push(tokens[i]);
        }
        else if (tokens[i] == "*")
        {
            while (operands.top() == "*")
            {
                string op = operands.top();
                operands.pop();
                postfix.push_back(op);
            }
            operands.push(tokens[i]);
        }
        else if (tokens[i] == ")")
        {
            while (operands.top() != "(")
            {
                string op = operands.top();
                operands.pop();
                postfix.push_back(op);
            }
            operands.pop();
        }
        else
            postfix.push_back(tokens[i]);
    }
    cout << "The postfix expression is: ";
    for (auto pf : postfix)
        cout << pf;
    cout << endl;
}

int strtoint(string s)
{
    int num = 0;
    for (auto i = 0; i < s.length(); i++)
        num = num * 10 + (s[i] - '0');
    return num;
}

int evaluatePostfix(vector<string> postfix)
{
    stack<int> operands;
    for (auto pf : postfix)
    {
        if (pf == "+" || pf == "*")
        {
            int op1 = operands.top();
            operands.pop();
            int op2 = operands.top();
            operands.pop();
            if (pf == "+")
                operands.push(op2 + op1);
            else if (pf == "*")
                operands.push(op2 * op1);
        }
        else
            operands.push(strtoint(pf));
    }
    return operands.top();
}

int main()
{
    // E ---> E + T | T
    // T ---> T * F | F
    // F ---> (E) | id

    string expr = "(7 + 5) * 3";
    vector<string> tokens, postfix;
    lex(expr, tokens);
    infixToPostfix(tokens, postfix);
    cout << "The postfix expressions evaluates to: " << evaluatePostfix(postfix) << endl;
    return 0;
}