#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll a1, a2, a3, b1, b2, b3;
ll s1, s2, s3, s4;

void ans()
{
    ll amaxb, aminb, maxb, minb;
    maxb = max(b1, b2);
    if (maxb == b1)
    {
        amaxb = a1;
        aminb = a2;
        minb = b2;
    }
    else
    {
        amaxb = a2;
        aminb = a1;
        minb = b1;
    }
    ll s11 = min((1LL * (maxb + a3) * max(a1 + a2, b3)), (1LL * (maxb + b3) * max(a1 + a2, a3)));
    ll s12 = min((1LL * (a1 + a2 + a3) * max({b1, b2, b3})), (1LL * (a1 + a2 + b3) * max({b1, b2, a3})));
    ll s13 = min((1LL * max(maxb, minb + a3) * (amaxb + max(aminb, b3))), (1LL * max(maxb, minb + b3) * (amaxb + max(aminb, a3))));
    cout << min({s11, s12, s13}) << '\n';
    return;
}

void not_main()
{
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    s1 = 1LL * (a1 + a2) * max(b1, b2);
    s2 = 1LL * (b1 + b2) * max(a1, a2);
    s3 = 1LL * (a1 + b2) * max(a2, b1);
    s4 = 1LL * (a2 + b1) * max(a1, b2);

    ll xmas = min({s1, s2, s3, s4});
    if (xmas == s1)
    {
        ans();
        return;
    }
    if (xmas == s2)
    {
        swap(a1, b1);
        swap(a2, b2);
        ans();
        return;
    }
    if (xmas == s3)
    {
        swap(a2, b2);
        ans();
        return;
    }
    if (xmas == s4)
    {
        swap(a1, b1);
        ans();
        return;
    }
    return;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RECS.INP", "r"))
    {
        freopen("RECS.INP", "r", stdin);
        freopen("RECS.OUT", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
    {
        not_main();
    }
    return 0;
}