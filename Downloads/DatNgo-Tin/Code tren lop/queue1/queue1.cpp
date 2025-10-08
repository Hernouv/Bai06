#include <bits/stdc++.h>
using namespace std;

int n, k, so;
queue<int> dayso;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> so;
        dayso.push(so);
    }
    k = k % n;
    for (int i = 1; i <= k; ++i)
    {
        dayso.push(dayso.front());
        dayso.pop();
    }
    while (dayso.empty() == false)
    {
        cout << dayso.front() << ' ';
        dayso.pop();
    }
    return 0;
}