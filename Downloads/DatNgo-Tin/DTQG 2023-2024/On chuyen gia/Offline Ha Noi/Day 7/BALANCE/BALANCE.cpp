#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
const int outbound = 1e9 + 7;
int N;
int a[nmax];
int res = 0, L = 1, R = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    a[N + 1] = -1;
    for (int i = 1; i <= N; ++i)
        cin >> a[i];
    while (R <= N)
    {
        while (a[R] >= R - L + 1)
            ++R;
        // cout << L << ' ' << R << ' ';
        res = max(res, R - L);
        while (a[R] < R - L + 1)
            ++L;
        // cout << L << ' ' << R << ' ' << res << '\n';
    }
    cout << res;
    return 0;
}