#include <bits/stdc++.h>
using namespace std;

bool erastos[1000010];
int arr[100010], u[100010], v[100010];
long long acc_sum[100010];
int n, p;

void sieve(int vmax)
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= vmax; ++i)
        if (erastos[i])
            for (int j = i * i; j <= vmax; j += i)
                erastos[j] = false;
}

void sub1(int vmax)
{
    sieve(vmax);
    int res = -1, resu, resv;
    for (int i = 1; i <= p; ++i)
    {
        int x = acc_sum[v[i]] - acc_sum[u[i] - 1];
        if (erastos[x])
        {
            res = max(res, x);
            resu = u[i], resv = v[i];
        }
    }
    cout << res << '\n';
    cout << resu << ' ' << resv;
}

bool prime(long long inp)
{
    if (inp < 1)
        return false;
    for (int i = 2; i * i <= inp; ++i)
        if (inp % i == 0)
            return false;
    return true;
}

void sub2()
{
    long long res = -1;
    for (int i = 1; i <= p; ++i)
    {
        long long x = acc_sum[v[i]] - acc_sum[u[i] - 1];
        if (prime(x))
            res = max(res, x);
    }
    cout << res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("QHD3.INP", "r", stdin);
    freopen("QHD3.OUT", "w", stdout);
    long long vmax = -1;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= p; ++i)
        cin >> u[i] >> v[i];
    acc_sum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        acc_sum[i] = acc_sum[i - 1] + arr[i];
        vmax = max(vmax, acc_sum[i]);
    }
    if (vmax <= 1e6)
        sub1(vmax);
    else
        sub2();
    return 0;
}