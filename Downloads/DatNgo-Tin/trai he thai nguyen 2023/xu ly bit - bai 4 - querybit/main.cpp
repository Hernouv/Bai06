#include <bits/stdc++.h>
using namespace std;

int cnt[52];
long long ans;
vector<long long> scan;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(cnt, 0, sizeof(cnt));
    int q, num = 0;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        string rq;
        cin >> rq;
        if (rq == "ADD" or rq == "DEL")
        {
            long long temp;
            cin >> temp;
            int s = 0;
            if (rq == "ADD")
            {
                num++;
                while (temp)
                {
                    cnt[s] += temp % 2;
                    s++, temp >>= 1;
                }
            }
            else if (rq == "DEL")
            {
                num--;
                while (temp)
                {
                    cnt[s] -= temp % 2;
                    s++, temp >>= 1;
                }
            }
        }
        else if (rq == "OR")
        {
            ans = 0;
            for (int i = 0; i <= 50; ++i)
                if (cnt[i]) ans += (1LL << i);
            cout << ans << '\n';
        }
        else if (rq == "AND")
        {
            ans = 0;
            for (int i = 0; i <= 50; ++i)
                if (cnt[i] == num) ans += (1LL << i);
            cout << ans << '\n';
        }
        else if (rq == "XOR")
        {
            ans = 0;
            for (int i = 0; i <= 50; ++i)
                if (cnt[i] & 1) ans += (1LL << i);
            cout << ans << '\n';
        }
    }
    return 0;
}
