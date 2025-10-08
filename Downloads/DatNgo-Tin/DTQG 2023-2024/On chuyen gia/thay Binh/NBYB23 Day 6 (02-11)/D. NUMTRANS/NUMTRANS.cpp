#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long

#define all(v) v.begin(), v.end()
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define db(val) "[" #val " = " << (val) << "] "

const int MAXN = 2e6 + 10;
const int inf = 1e12 + 10;

map<int, int> factor(int x)
{
    map<int, int> res;

    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            res[i]++;
            x /= i;
        }
    }

    if (x > 1)
        res[x]++;

    return res;
}

void solve()
{
    int A, B, D;
    cin >> A >> B >> D;

    if (A == B)
    {
        cout << 0;
        return;
    }

    if (B % A == 0 and B / A <= D)
    {
        cout << 1;
        return;
    }

    if (A % B == 0 and A / B <= D)
    {
        cout << 1;
        return;
    }

    if (A < B and B <= D)
    {
        cout << 2;
        return;
    }

    if (B < A and A <= D)
    {
        cout << 2;
        return;
    }

    int fval_up = 1, fval_down = 1;
    auto fA = factor(A), fB = factor(B);
    map<int, int> req;

    for (auto &[u, v] : fA)
        if (fB.count(u) == 0)
            fB[u] = 0;
    for (auto &[u, v] : fB)
    {
        req[u] = fA[u] - v;
        REP(_, abs(req[u]))
        {
            if (req[u] > 0)
                fval_down *= u;
            else
                fval_up *= u;
        }
    }

    if (fB.rbegin()->first > D)
    {
        cout << -1;
        return;
    }

    int ans = 0;
    auto add = [&](int x)
    {
        vector<int> div;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i > 1)
                    div.push_back(i);
                if (i * i != x)
                    div.push_back(x / i);
            }
        }

        sort(all(div));

        clog << db(x) << '\n';

        while (div.size() and div.back() > D)
            div.pop_back();

        while (1)
        {
            if (div.empty())
                break;
            if (x <= 1)
                break;

            int d = div.back();

            while (x % d == 0)
            {
                ans++;
                x /= d;
            }

            div.pop_back();
        }
    };

    add(fval_down);
    add(fval_up);

    cout << ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}