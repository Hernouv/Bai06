#include <bits/stdc++.h>
using namespace std;

string inp;
int digit[15], prime[5000], sz, cnt = 0;
bool chosen[15];
bool erastos[33010];

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    for (int i = 2; i * i <= 33000; ++i)
        if (erastos[i])
            for (int j = i * i; j <= 33000; j += i)
                erastos[j] = false;

    int id = 1;
    for (int i = 2; i <= 33000; ++i)
        if (erastos[i])
            prime[id++] = i;
}

void conv()
{
    for (int i = 1; i <= sz; ++i)
        digit[i] = inp[i - 1] - '0';
    sort(digit + 1, digit + sz + 1);
}

void primecheck()
{
    do
    {
        long long num = 0;
        for (int i = 1; i <= sz; ++i)
        {
            num *= 10;
            num += digit[i];
        }
        bool check = true;
        if (num < 2)
            check = false;
        else
        {
            for (int i = 1; prime[i] * prime[i] <= num; ++i)
                if (num % prime[i] == 0)
                {
                    check = false;
                    break;
                }
        }
        if (check)
            cnt++;
    } while (next_permutation(digit + 1, digit + sz + 1));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PERMUTAT.INP", "r", stdin);
    freopen("PERMUTAT.OUT", "w", stdout);
    memset(chosen, true, sizeof(chosen));
    sieve();
    cin >> inp;
    sz = inp.size();
    conv();
    primecheck();
    cout << cnt;
    return 0;
}