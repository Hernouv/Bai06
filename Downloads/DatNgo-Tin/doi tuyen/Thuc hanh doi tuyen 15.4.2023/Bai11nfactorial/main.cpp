#include <bits/stdc++.h>
using namespace std;

int main()
{
    double res = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++ i)
        res *= n;
    cout << fixed << setprecision(1) << res;
    return 0;
}
