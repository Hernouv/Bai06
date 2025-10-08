#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 1e6 + 10;

ll l, r;
int digit_cnt1, digit_cnt2, mid_digit, st, en;
int proc[nmax];

void reverse(ll &inp)
{
    ll ret = 0;
    while (inp)
    {
        ret += (inp % 10);
        inp /= 10;
    }
    inp = ret;
}

void solve()
{
    if (!(digit_cnt1 & 1))
        l = pow(10, digit_cnt1 + 1);
    if (!(digit_cnt2 & 1))
        r = pow(10, digit_cnt2 - 1);

    if (l > r)
    {
        cout << 0;
        return;
    }

    ll left_half1 = l / (ll)pow(10, (digit_cnt1 >> 1));
    mid_digit = left_half1 % 10;
    left_half1 /= 10;
    ll right_half1 = l % (ll)pow(10, (digit_cnt1 >> 1));
    reverse(right_half1);

    if (left_half1 >= right_half1)
        st = left_half1 * 10 + mid_digit;
    else
        st = right_half1 * 10 + mid_digit;

    ll left_half2 = r / (ll)pow(10, (digit_cnt2 >> 1));
    mid_digit = left_half2 % 10;
    left_half2 /= 10;
    ll right_half2 = r % (ll)pow(10, (digit_cnt2 >> 1));
    reverse(right_half2);

    if (left_half2 > right_half2)
        --left_half2;
    en = left_half2 * 10 + mid_digit;
}

void not_main()
{
    cin >> l >> r;
    int digit_cnt1 = log10(l);
    int digit_cnt2 = log10(r);
    if (digit_cnt1 == digit_cnt2 and digit_cnt1 % 2 == 0)
        cout << 0;
    else
        solve();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PALINPRIME.INP", "r"))
    {
        freopen("PALINPRIME.INP", "r", stdin);
        freopen("PALINPRIME.OUT", "w", stdout);
    }
    not_main();
    return 0;
}