#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

typedef long long ll;
int n;
ll k, fact[22];
int a[nmax], soldier[nmax];

void setFact()
{
    fact[0] = 1;
    for (int i = 1; i <= 20; ++i)
        fact[i] = fact[i - 1] * i;
}

void proc()
{
    vector<int> num;
    for (int i = 0; i <= n; ++i)
        num.push_back(i);

    int it = 1;
    while (it <= n)
    {
        if (n - it >= 20)
        {
            soldier[it] = it;
            num.erase(num.begin() + 1);
            ++it;
            continue;
        }
        ll t_pos = k / fact[n - it];
        if (k % fact[n - it])
            ++t_pos;
        soldier[it] = num[t_pos];
        num.erase(num.begin() + t_pos);
        k -= (t_pos - 1) * fact[n - it];
        ++it;
    }
}

void not_main()
{
    setFact();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    proc();
    for (int i = 1; i <= n; ++i)
        cout << soldier[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SAPXEP.INP", "r"))
    {
        freopen("SAPXEP.INP", "r", stdin);
        freopen("SAPXEP.OUT", "w", stdout);
    }
    not_main();
    return 0;
}