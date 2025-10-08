#include <bits/stdc++.h>

#define MAX 100000
#define MOD 1000000007

typedef long long llint;

int n;
char gore[MAX + 1];
char dole[MAX + 1];
char most[MAX + 1];

int m;
int grupe[MAX];

int dp[MAX][2][2];

int main(void)
{
    scanf("%d ", &n);
    gets(gore);
    for (int i = 0; i < n; ++i)
        gore[i] -= '0';
    gets(dole);
    for (int i = 0; i < n; ++i)
        dole[i] -= '0';
    gets(most);
    for (int i = 0; i < n; ++i)
        most[i] -= '0';

    dp[0][0][0] = 1;
    dp[0][0][1] = most[0];
    dp[0][1][0] = most[0];
    dp[0][1][1] = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i][0][0] = (dp[i - 1][0][0] * gore[i] + dp[i - 1][0][1] * dole[i] * most[i]) % MOD;
        dp[i][0][1] = (dp[i - 1][0][1] * dole[i] + dp[i - 1][0][0] * gore[i] * most[i]) % MOD;
        dp[i][1][0] = (dp[i - 1][1][0] * gore[i] + dp[i - 1][1][1] * dole[i] * most[i]) % MOD;
        dp[i][1][1] = (dp[i - 1][1][1] * dole[i] + dp[i - 1][1][0] * gore[i] * most[i]) % MOD;
    }
    int ret = (dp[n - 1][0][0] * gore[0] + dp[n - 1][1][1] * dole[0]) % MOD;

    grupe[m++] = most[0];
    for (int i = 1; i < n; ++i)
    {
        if (gore[i] && dole[i])
            grupe[m - 1] += most[i];
        else
            grupe[m++] = most[i];
    }
    if (gore[0] && dole[0])
        grupe[0] += grupe[--m];

    if (m == 0)
    {
        grupe[0] /= 2;
        ret = (ret + (llint)grupe[0] * (grupe[0] - 1)) % MOD;
    }
    else
    {
        for (int i = 0; i < m; ++i)
            ret = (ret + (llint)grupe[i] * (grupe[i] - 1) / 2) % MOD;
    }

    printf("%d\n", ret);

    return 0;
}
