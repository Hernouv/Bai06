#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int nmax = 1e5 + 10;

vector<int> dem;
int n, k, maxcnt = 0;
ll res = 0;
int length_cnt[nmax];
string s;

void not_main()
{
    cin >> n >> k;
    cin >> s;
    s += ' ';
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ++cnt;
        if (s[i] != s[i + 1])
        {
            maximize(maxcnt, cnt);
            length_cnt[cnt]++;
            cnt = 0;
        }
    }
    int it = maxcnt;
    while (k)
    {
        if (length_cnt[it] <= k)
        {
            length_cnt[it - 1] += length_cnt[it];
            k -= length_cnt[it];
            length_cnt[it] = 0;
            --it;
        }
        else
        {
            length_cnt[it] -= k;
            length_cnt[it - 1] += k;
            k = 0;
        }
    }
    for (int i = it; i >= 1; --i)
        if (length_cnt[i])
            res += 1LL * length_cnt[i] * i * (i + 1) / 2;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STRDEL.INP", "r"))
    {
        freopen("STRDEL.INP", "r", stdin);
        freopen("STRDEL.OUT", "w", stdout);
    }
    not_main();
    return 0;
}