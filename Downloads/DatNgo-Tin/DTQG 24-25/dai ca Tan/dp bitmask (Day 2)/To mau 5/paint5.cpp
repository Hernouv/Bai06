#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> valid_val;
int n;
int dp[100005][30];
int res = 0;

bool valid_check(int m1, int m2)
{
    if (m1 % 3 == m2 % 3)
        return false;
    m1 /= 3, m2 /= 3;
    if (m1 % 3 == m2 % 3)
        return false;
    m1 /= 3, m2 /= 3;
    if (m1 % 3 == m2 % 3)
        return false;
    return true;
}

void not_main()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if (i != j and j != k)
                    valid_val.push_back(i * 9 + j * 3 + k);

    cin >> n;
    if (n == 1)
    {
        cout << 12;
        return;
    }

    for (int msk : valid_val)
        dp[1][msk] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int msk1 : valid_val)
            for (int msk2 : valid_val)
                if (valid_check(msk1, msk2))
                    dp[i][msk1] = (dp[i][msk1] + dp[i - 1][msk2]) % mod;
    }

    for (int msk : valid_val)
        res = (res + dp[n][msk]) % mod;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}