#include <bits/stdc++.h>
using namespace std;

long long dp[1000010];
long long A[1000010];
int n;

void sol()
{
    int st = 1, en;
    while (st < n)
    {
        en = st + 1;
        if (A[en] <= A[st])
            while (en + 1 <= n && A[en + 1] <= A[en])
                en++;
        else
            while (en + 1 <= n && A[en + 1] >= A[en])
                en++;
        for (int i = max(en - 1, st + 1); i <= en; i++)
        {
            dp[i + 1] = max(dp[st] + abs(A[st] - A[i]), dp[st + 1] + abs(A[st + 1] - A[i]));
        }
        st = en;
    }
    cout << dp[n + 1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    sol();
    return 0;
}