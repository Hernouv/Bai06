#include <bits/stdc++.h>
using namespace std;

int erastos[10000010];
int n[100010], k[100010];
int vmax = 0, t;

void sieve(int lim)
{
    for (int i = 2; i <= lim; ++i)
        erastos[i] = i;
    for (int i = 2; i * i <= lim; ++i)
        if (erastos[i] == i)
            for (int j = i * i; j <= lim; j += i)
                erastos[j] = i;
}

long long power(int a, int b)
{
    int ret = 1;
    for (int i = 1; i <= b; ++i)
        ret *= a;
    return ret;
}

void proc()
{
    sieve(vmax);
    long long res;
    for (int i = 1; i <= t; ++i)
    {
        res = 1;
        map<int, int> expo;
        int temp = n[i];
        while (temp > 1)
        {
            int pr = erastos[temp];
            while (temp % pr == 0)
                temp /= pr, expo[pr]++;
            expo[pr] += (expo[pr] & 1);
        }
        temp = k[i];
        while (temp > 1)
        {
            int pr = erastos[temp];
            if (!expo[pr])
            {
                while (temp % pr == 0)
                    temp /= pr, expo[pr]++;
                expo[pr] %= 2;
            }
            else
            {
                int t_exp = 0;
                while (temp % pr == 0)
                    temp /= pr, t_exp++;
                if (t_exp >= pr)
                    expo[pr] = 0;
                else
                    expo[pr] -= t_exp;
                expo[pr] += ((t_exp + expo[pr]) & 1);
            }
        }
        for (auto x : expo)
            res *= power(x.first, x.second);
        cout << res << '\n';
    }
}

void sub2()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n[i] >> k[i];
        vmax = max({vmax, n[i], k[i]});
    }
    proc();
    return 0;
}
