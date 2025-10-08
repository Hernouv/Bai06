#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 3;
int n;
ll a[N];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    //freopen("consmov.inp", "r", stdin);
    //freopen("consmov.out", "w", stdout);
    cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = 1, ans = 0;
	while(r <= n)
    {
		while(a[r] - a[l] + 1 > n) ++l;
		ans = max(ans, r - l + 1);
		++r;
	}
	if((a[n - 1] - a[1] + 1 == n - 1 and a[n] - a[n - 1] > 2) or (a[n] - a[2] + 1 == n - 1 and a[2] - a[1] > 2))
		cout << 2 << '\n';
	else
		cout << n - ans << '\n';
	cout << max(a[n] - a[2], a[n - 1] - a[1]) - n + 2;
    return 0;
}
