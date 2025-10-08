#include <bits/stdc++.h>
using namespace std;

struct Fenwick
{
    int n;
    vector<int> fenw;
    Fenwick(int n) : n(n), fenw(n + 1, 0) {}
    void update(int i, int v)
    {
        for (; i <= n; i += i & (-i))
            fenw[i] += v;
    }
    int query(int i)
    {
        int s = 0;
        for (; i > 0; i -= i & (-i))
            s += fenw[i];
        return s;
    }
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[S[i]] = i;
    }

    Fenwick fenw(n);
    vector<long long> P(n + 1, 0);
    fenw.update(pos[1], 1);
    for (int i = 2; i <= n; i++)
    {
        int smaller = fenw.query(pos[i]);
        int greater = (i - 1) - smaller;
        P[i] = P[i - 1] + greater;
        fenw.update(pos[i], 1);
    }

    Fenwick fenw2(n);
    vector<long long> D(n + 2, 0);
    fenw2.update(pos[n], 1);
    for (int i = n - 1; i >= 1; i--)
    {
        int inv_new = fenw2.query(pos[i] - 1);
        D[i] = D[i + 1] + inv_new;
        fenw2.update(pos[i], 1);
    }

    long long ans = LLONG_MAX;
    for (int v = 1; v <= n; v++)
    {
        long long val = P[v - 1] + D[v + 1];
        if (val < ans)
            ans = val;
    }

    cout << ans << "\n";

    return 0;
}
