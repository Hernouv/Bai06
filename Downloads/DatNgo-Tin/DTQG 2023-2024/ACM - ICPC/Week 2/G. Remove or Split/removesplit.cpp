#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, sum = 0, num;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        sum += num;
    }
    if (sum % 2)
        cout << "Bob";
    else
        cout << "Alice";
    return 0;
}