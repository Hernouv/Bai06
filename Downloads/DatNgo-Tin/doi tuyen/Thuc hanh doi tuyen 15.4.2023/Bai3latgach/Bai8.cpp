#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Bai8.INP","r",stdin);
    freopen("Bai8.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    int i = (a-2)*(b-2);
    cout << i << '\n' << a*b - i;
    return 0;
}
