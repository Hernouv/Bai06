#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
P p[50005];

int main()
{
    int n, u, v, ans = 0, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);

    ans++, u = p[0].second, v = p[0].first;
    for (int i = 1; i < n;)
    {
        while (i < n and p[i].second < v)
            i++;
        if (i == n)
            break;
        ans++, u = p[i].second, v = p[i].first;
    }
    cout << ans;
    return 0;
}