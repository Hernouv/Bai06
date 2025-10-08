#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai24.INP","r",stdin);
    freopen("bai24.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort (a, a + 3, greater<int>());
    cout << a[0] + a[1];
    return 0;
}
