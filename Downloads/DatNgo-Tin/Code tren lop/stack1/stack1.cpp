#include <bits/stdc++.h>
using namespace std;

stack<int> dayso;
int n;
int so;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> so;
        dayso.push(so);
    }
    while (dayso.empty() == false)
    {
        cout << dayso.top() << endl;
        dayso.pop();
    }
    return 0;
}