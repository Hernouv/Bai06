#include <bits/stdc++.h>
using namespace std;

int arr[110], k;

void proc(int num)
{
    long long s = 0;
    int i = 1;
    while (i * i < num)
    {
        if (num % i == 0)
        {
            s += i + num / i;
        }
        i++;
    }
    if (num / i == i)
        s += i;
    if (2 * num <= s)
        cout << 1;
    else
        cout << 0;
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);
    cin >> k;
    int num;
    for (int i = 1; i <= k; ++i)
    {
        cin >> num;
        proc(num);
    }
    return 0;
}