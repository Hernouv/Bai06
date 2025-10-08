#include <bits/stdc++.h>
using namespace std;

#define ll long long
int m, n;
ll k[100010], s[100010], t[100010];
vector<pair<ll, ll>> proc;

void sub1()
{
    for (int i = 1; i <= m; ++i)
        proc.emplace_back(s[i], k[i]);
    sort(proc.begin(), proc.end());
    proc.emplace_back(0, 0);
    ll core_in_need = 0;
    ll res = 0;
    for (int i = 0, sz = proc.size() - 1; i < sz; ++i)
    {
        if (proc[i].first == proc[i + 1].first)
            core_in_need += proc[i].second;
        else
        {
            core_in_need += proc[i].second;
            res = max(res, core_in_need);
            core_in_need = 0;
        }
    }
    cout << res;
}

void sub3()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("schedule.inp", "r", stdin);
    freopen("schedule.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cin >> k[i] >> s[i] >> t[i];

    bool s1 = true;
    for (int i = 1; i <= m; ++i)
        if (s[i] != t[i])
        {
            s1 = false;
            break;
        }
    if (s1)
        sub1();
    else
    {
        bool s3 = true;
        for (int i = 1; i <= m; ++i)
            if (k[i] != 1)
            {
                s3 = false;
                break;
            }
        if (s3)
            sub3();
    }
    return 0;
}