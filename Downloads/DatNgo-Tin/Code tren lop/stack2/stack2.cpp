#include <bits/stdc++.h>
using namespace std;

string nhap;
stack<char> xuly;
bool khongxulyhet;

int main()
{
    cin >> nhap;
    for (int i = 0; i < nhap.size(); ++i)
    {
        if (nhap[i] == '(')
            xuly.push(nhap[i]);
        else if (nhap[i] == ')')
            if (xuly.empty() == true)
            {
                khongxulyhet = true;
                cout << "NO";
                break;
            }
            else
                xuly.pop();
    }
    if (khongxulyhet == false)
    {
        if (xuly.empty() == true)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}
