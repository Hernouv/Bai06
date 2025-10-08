#include <bits/stdc++.h>
using namespace std;

const int cnst = 100001;
int n;
string inp;
long long res = 0;
long long mask[cnst], diff[cnst], cnt[cnst];

int main()
{
    cin >> n >> inp;
    inp = ' ' + inp;
    mask[0] = diff[0] = 0, cnt[0] = 1;
    for (int i = 1; i <= n; ++i)
        mask[i] = mask[i - 1] ^ (1 << (inp[i] - 'a'));
    int scan = 0;
    sort (mask + 1, mask + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        if (mask[i] == mask[i - 1]) cnt[scan]++;
        else
        {
            diff[++scan] = mask[i];
            cnt[scan] = 1;
        }
    }
    for (int i = 0; i <= scan; ++i)
    {
        if (cnt[i] > 1) res += ((cnt[i]) * (cnt[i] - 1)) >> 1;
        for (int k = 0; k <= 26; ++k)
        {'
            if (binary_search(diff + i, diff + scan + 1, (diff[i] ^ (1 << k))))
            {
                int pos = lower_bound(diff + i, diff + scan, (diff[i] ^ (1 << k))) - diff;
                res += cnt[pos] * cnt[i];
            }
        }
    }
    cout << res;
    return 0;
}
