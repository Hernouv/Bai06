#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r)
{
    return l + rand() % (r - l + 1);
}

void not_main()
{
    int n = randInt(1, 1000);
    cout << n << '\n';
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = randInt(1, 1000);
        cout << tmp << ' ';
        res += tmp;
    }
    cerr << res;
}

int32_t main(void)
{
    freopen("demo.inp", "w", stdout);
    srand(time(nullptr));
    not_main();
}
