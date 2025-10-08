#include <bits/stdc++.h>
using namespace std;

#define int long long

bool NT[1000010];
vector<int> primes;
void sang(int x)
{
    memset(NT, true, sizeof(NT));
    NT[0] = NT[1] = false;
    for (int i = 2; i <= x; i++)
    {
        if (NT[i] == true)
        {
            for (int j = 2 * i; j <= x; j += i)
            {
                NT[j] = false;
            }
        }
    }

    for (int i = 2; i <= x; i++)
        if (NT[i] == true)
            primes.push_back(i);
}

int n, m;
int res[100010];
void calc(int x)
{
    for (int i = 0; i <= 10000; i++)
        res[i] = 1;
    for (int p : primes)
    {
        if (p > x)
            break;
        for (int i = x; i >= p - 1; i--)
        {
            int tmp = p;
            while (0 < tmp && tmp <= i)
            {
                res[i] = (res[i] + (res[i - tmp] * (tmp)) % m) % m;
                tmp *= p;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    sang(10010);
    calc(10000);
    cout << res[n];
    return 0;
}