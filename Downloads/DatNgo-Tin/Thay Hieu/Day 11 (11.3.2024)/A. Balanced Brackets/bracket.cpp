#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> proc;

void not_main()
{
    while (!proc.empty())
        proc.pop();

    for (char ch : s)
    {
        if (ch == '(' or ch == '{' or ch == '[')
        {
            proc.push(ch);
            continue;
        }

        if (ch == ')' or ch == '}' or ch == ']' and proc.empty())
        {
            cout << "N\n";
            return;
        }

        else if (ch == ')')
        {
            char t = proc.top();
            if (t == '(')
                proc.pop();
            else
            {
                cout << "N\n";
                return;
            }
        }

        else if (ch == '}')
        {
            char t = proc.top();
            if (t == '{')
                proc.pop();
            else
            {
                cout << "N\n";
                return;
            }
        }

        else if (ch == ']')
        {
            char t = proc.top();
            if (t == '[')
                proc.pop();
            else
            {
                cout << "N\n";
                return;
            }
        }
    }

    cout << 1;
    if (proc.empty())
        cout << "Y\n";
    else
        cout << "N\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("null.inp", "r"))
    {
        freopen("null.inp", "r", stdin);
        freopen("null.out", "w", stdout);
    }

    while (cin >> s)
        not_main();
    return 0;
}