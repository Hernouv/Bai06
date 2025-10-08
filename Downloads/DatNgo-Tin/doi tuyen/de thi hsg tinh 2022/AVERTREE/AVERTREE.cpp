#include <bits/stdc++.h>
using namespace std;

int n, k;
double arr[100010];

void sub1()
{
    double res = -0x3f;
    for (int i = 1; i <= n; ++i)
        res = max(res, arr[i]);
    cout << setprecision(3) << fixed << res;
}

bool check(double mid)
{
    vector<double> scan(n + 1);
    for (int i = 1; i <= n; ++i)
        scan[i] = scan[i - 1] + arr[i] - mid;
    double mVal = 0;
    for (int i = k; i <= n; ++i)
    {
        if (mVal <= scan[i])
            return true;
        mVal = min(mVal, scan[i - k + 1]);
    }
    return false;
}

void sub4()
{
    for (int i = 1; i <= n; ++i)
        arr[i] *= 100000.0;
    double l = *min_element(arr + 1, arr + n + 1);
    double r = *max_element(arr + 1, arr + n + 1);
    double res = 0;
    while (l <= r)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << setprecision(3) << fixed << res / 100000.0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("AVERTREE.INP", "r", stdin);
    // freopen("AVERTREE.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    if (k == 1)
        sub1();
    else
        sub4();
    return 0;
}