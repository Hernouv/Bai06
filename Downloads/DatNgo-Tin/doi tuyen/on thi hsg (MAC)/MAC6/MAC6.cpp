#include <bits/stdc++.h>
using namespace std;

bool erastos[32010];
long long prime[10000], id = 0;
vector<long long> out1, out2;

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= 32000; ++i)
        if (erastos[i])
            for (int j = i * i; j <= 32000; j += i)
                erastos[j] = false;

    for (long long i = 2; i <= 32000; ++i)
        if (erastos[i])
            prime[++id] = i;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("MAC6.INP", "r", stdin);
    freopen("MAC6.OUT", "w", stdout);
    sieve();
    long long l, r;
    cin >> l >> r;
    if (l == 1)
    {
        l++;
        if (r < l)
            r++;
    }
    long long sr = ceil(sqrt(r));
    for (long long i = l; i <= r; ++i)
        out1.push_back(i);
    int org = 1;
    for (long long i = 1; prime[i] <= sr; ++i)
    {
        if (org == 1)
        {
            for (auto x : out1)
                if (x % prime[i] != 0 or x == prime[i])
                    out2.push_back(x);
            out1.clear();
        }
        else
        {
            for (auto x : out2)
                if (x % prime[i] != 0 or x == prime[i])
                    out1.push_back(x);
            out2.clear();
        }
        org = 3 - org;
    }
    cout << max(out1.size(), out2.size());
    return 0;
}
// noooo qiqiiii...