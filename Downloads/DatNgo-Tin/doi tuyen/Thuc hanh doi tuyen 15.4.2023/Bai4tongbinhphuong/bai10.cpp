#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai10.INP","r",stdin);
    freopen("bai10.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    long long s;
    s = n*(n+1)*(2*n+1)/6;
    cout << s;
    return 0;
}
