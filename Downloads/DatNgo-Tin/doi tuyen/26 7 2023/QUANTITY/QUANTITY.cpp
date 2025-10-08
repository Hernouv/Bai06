#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull muldigit[1000010];
pair<ull, ull> q[1000010];

void setVal()
{
    for (ull i = 0; i < 10; ++i)
        muldigit[i] = i;
    for (ull i = 1; i <= 1000000; ++i)
        muldigit[i] = muldigit[i / 10] * (i % 10);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("QUANTITY.INP", "r", stdin);
    // freopen("QUANTITY.OUT", "w", stdout);
    setVal();
    return 0;
}