#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<ll, ll> ll2;
#define fi first
#define se second

const int lim = 1e6 + 10;
const int nmax = 2e5 + 10;

multiset<lli> linesL;
multiset<lli> linesR;
ll2 lineinfo[lim];

int N;
ll L, R;

void not_main()
{
    cin >> L >> R >> N;
    char qtype;
    int qid;
    ll qs, qt;
    for (int i = 1; i <= N; ++i)
    {
        cin >> qtype;
        if (qtype == '+')
        {
            cin >> qid >> qs >> qt;
            if (qs <= L or qt >= R)
            {
                if (qs <= L)
                    linesL.insert({qt, qid});
                if (qt >= R)
                    linesR.insert({qs, qid});
                lineinfo[qid] = {qs, qt};
                if (qs > L)
                    lineinfo[qid].se = -qt - 1;
                if (qt < R)
                    lineinfo[qid].fi = -qs - 1;
            }
        }
        else
        {
            cin >> qid;
            if (lineinfo[qid].se >= 0)
                linesL.erase({lineinfo[qid].se, qid});
            if (lineinfo[qid].fi >= 0)
                linesR.erase({lineinfo[qid].fi, qid});
        }
        if (!linesL.empty())
        {
            lli maxR = *linesL.rbegin();
            if (maxR.fi >= R)
            {
                cout << 1 << '\n';
                continue;
            }
        }
        bool fwd = true;
        if (!linesL.empty() and !linesR.empty())
        {
            lli maxR = *linesL.rbegin();
            for (auto x : linesR)
            {
                if (x.fi <= maxR.fi and x.se != maxR.se)
                {
                    cout << 2 << '\n';
                    fwd = false;
                    break;
                }
                else if (x.fi > maxR.fi)
                    break;
            }
        }
        if (!fwd)
            continue;
        cout << -1 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}