#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> valid_val;
vector<int> coup_valid[3150];
int n;
int dp[1005][3150];
int res = 0;

bool valid_check(int m1, int m2)
{
    if (m1 % 5 == m2 % 5)
        return false;
    m1 /= 5, m2 /= 5;
    if (m1 % 5 == m2 % 5)
        return false;
    m1 /= 5, m2 /= 5;
    if (m1 % 5 == m2 % 5)
        return false;
    m1 /= 5, m2 /= 5;
    if (m1 % 5 == m2 % 5)
        return false;
    m1 /= 5, m2 /= 5;
    if (m1 % 5 == m2 % 5)
        return false;
    return true;
}

void not_main()
{
    for (int i1 = 0; i1 < 5; ++i1)
        for (int i2 = 0; i2 < 5; ++i2)
            for (int i3 = 0; i3 < 5; ++i3)
                for (int i4 = 0; i4 < 5; ++i4)
                    for (int i5 = 0; i5 < 5; ++i5)
                        if (i1 != i2 and i2 != i3 and i3 != i4 and i4 != i5)
                            valid_val.push_back(i5 + i4 * 5 + i3 * 25 + i2 * 125 + i1 * 625);

    int vsz = valid_val.size();
    for (int i = 0; i < vsz - 1; ++i)
        for (int j = i + 1; j < vsz; ++j)
            if (valid_check(valid_val[i], valid_val[j]))
            {
                coup_valid[valid_val[i]].push_back(valid_val[j]);
                coup_valid[valid_val[j]].push_back(valid_val[i]);
            }

    cin >> n;
    if (n == 1)
    {
        cout << 1280;
        return;
    }

    for (int msk : valid_val)
        dp[1][msk] = 1;

    for (int i = 2; i <= n; ++i)
        for (int msk1 : valid_val)
            for (int msk2 : coup_valid[msk1])
                dp[i][msk1] = (dp[i][msk1] + dp[i - 1][msk2]) % mod;

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