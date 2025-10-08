#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, P, Q;
int fibo[int(1e6) + 1];
map<int, bool> if_fibo;
int arr[nmax];

void create_fiboseq()
{
    if_fibo[0] = true;
    fibo[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        if_fibo[fibo[i]] = true;
    }
}

void not_main()
{
    create_fiboseq();
    cin >> n >> P >> Q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    if (n == 1)
        if (if_fibo[arr[1]])
            cout << 1;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SEQ.inp", "r"))
    {
        freopen("SEQ.inp", "r", stdin);
        freopen("SEQ.out", "w", stdout);
    }
    not_main();
    return 0;
}