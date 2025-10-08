#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll L, R;
    cin >> L >> R;
    ll res = 0;
    ll d = 1;
    while (d <= R)
    {
        ll q = R / d;
        if (q == 0)
        {
            break;
        }
        ll next_d = R / q;
        next_d = min(next_d, R);
        ll floor_Lm1_q;
        if (L == 0)
        {
            floor_Lm1_q = 0;
        }
        else
        {
            floor_Lm1_q = (L - 1) / q;
        }
        ll low_d = max(d, floor_Lm1_q + 1);
        ll high_d = next_d;
        if (low_d <= high_d)
        {
            ll sum_high = high_d * (high_d + 1) / 2;
            ll sum_lowm1 = (low_d - 1) * (low_d) / 2;
            res += (sum_high - sum_lowm1);
        }
        d = next_d + 1;
    }
    cout << res;
    return 0;
}
