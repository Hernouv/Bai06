#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;

int erastos[nmax];
int n, res = 0;

void sieve()
{
    for (int i = 1; i <= 100000; ++i)
        erastos[i] = i;

    for (int i = 2; i <= 100000; ++i)
        if (erastos[i] == i)
        {
            ++res;
            for (int j = i * i; j <= 100000; j += i)
                erastos[j] = i;
        }
}

// void check_palin()
// {
//     for (int i = 2; i <= n; ++i)
//         if (erastos[i] == i)
//         {
//             bool palin = true;
//             int tnum = i;
//             string tmp;
//             while (tnum)
//             {
//                 tmp += (tnum % 10);
//                 tnum /= 10;
//             }
//             int sz = tmp.size(), t = sz - 1;
//             for (int j = 0; j < sz / 2; ++j)
//                 if (tmp[j] != tmp[t - j])
//                 {
//                     palin = false;
//                     break;
//                 }
//             if (palin)
//             ++res;
//         }
// }

void not_main()
{
    // n = 100000;
    sieve();
    // check_palin();
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("NPALIPRI.INP", "r"))
    {
        freopen("NPALIPRI.INP", "r", stdin);
        freopen("NPALIPRI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}