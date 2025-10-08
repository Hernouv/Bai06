//"blindfold" challenge
#include <bits/stdc++.h>
using namespace std;

int r_backw[100010][3];
int arr[100010];
string inp;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    cin >> inp;
    int n = inp.size();
    for (int i = 1; i <= n; ++i)
        arr[i] = inp[i - 1] - '0';
    int s = 0;
    for (int i = n; i > 0; --i)
    {
        s += arr[i];
        int k = s % 3;
        r_backw[i][k] = r_backw[i + 1][k] + 1;
        r_backw[i][(k + 1) % 3] = r_backw[i + 1][(k + 1) % 3];
        r_backw[i][(k + 2) % 3] = r_backw[i + 1][(k + 2) % 3];
    }
    s = 0;
    long long res = r_backw[1][0];
    for (int i = 1; i < n; ++i)
    {
        s += arr[i];
        int k = s % 3;
        if (!k)
            res++;
        res += r_backw[i + 2][(3 - k) % 3];
    }
    cout << res;
    return 0;
}