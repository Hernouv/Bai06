#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T>
inline bool minimize(T &a, T b) {return a > b ? a = b, 1 : 0;}

#define whole(__) __.begin(), __.end()
using ll = long long;
const int nmax = 1e5 + 10;
const ll oo = 1e18;

int n;
int h[nmax], pos[nmax];
int cnt_less[nmax];
ll res = 0;

vector<int> seq;

void sub2()
{
    ll ans = oo;

    for (int i = n; i >= 1; --i)
        {
            int p = lower_bound(whole(seq), h[i]) - seq.begin();
            cnt_less[i] = p;
            seq.insert(seq.begin() + p, h[i]);
        }

    ll tres = 0;
    for (int i = 1; i <= n; ++i)
        tres += abs(h[i] - (i + cnt_less[i]));

    minimize(ans, tres);

    for (int p1 = 1; p1 < n; ++p1)
        for (int p2 = p1 + 1; p2 <= n; ++p2)
        {
            swap(h[p1], h[p2]);

            seq.clear();

            for (int i = n; i >= 1; --i)
            {
                int p = lower_bound(whole(seq), h[i]) - seq.begin();
                cnt_less[i] = p;
                seq.insert(seq.begin() + p, h[i]);
            }

            ll tres = 0;
            for (int i = 1; i <= n; ++i)
                tres += abs(h[i] - (i + cnt_less[i]));

            minimize(ans, tres + 1);
            swap(h[p1], h[p2]);
        }
    cout << ans;
    return;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    if (n <= 200)
    {
        sub2();
        return;
    }

    for (int i = 1; i <= n; ++i)
        pos[h[i]] = i;

    for (int i = n; i >= 1; --i)
    {
        int p = lower_bound(whole(seq), h[i]) - seq.begin();
        cnt_less[i] = p;
        seq.insert(seq.begin() + p, h[i]);
    }

    for (int i = 1; i <= n; ++i)
        res += abs(h[i] - (i + cnt_less[i]));

    int pmax = 0, pval = -1;

    for (int i = 1; i <= n; ++i)
    {
        if (maximize(pval, abs(h[i] - (i + cnt_less[i]))))
            pmax = i;
    }

    int tcnt = 0;
    for (int i = n; i > h[pmax]; --i)
        if (h[i] < h[pmax])
            ++tcnt;
    swap(h[pmax], h[h[pmax] - tcnt]);

    seq.clear();

    for (int i = n; i >= 1; --i)
    {
        int p = lower_bound(whole(seq), h[i]) - seq.begin();
        cnt_less[i] = p;
        seq.insert(seq.begin() + p, h[i]);
    }

    ll tres = 0;
    for (int i = 1; i <= n; ++i)
        tres += abs(h[i] - (i + cnt_less[i]));

    minimize(res, tres + 1);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("HOANVI.INP","r"))
    {
        freopen("HOANVI.INP","r",stdin);
        freopen("HOANVI.OUT","w",stdout);
    }
    not_main();
    return 0;
}
