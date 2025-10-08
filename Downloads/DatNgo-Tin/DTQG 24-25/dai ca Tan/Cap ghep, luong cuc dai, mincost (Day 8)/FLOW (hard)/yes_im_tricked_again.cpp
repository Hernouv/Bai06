#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    ll b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    ll win1 = max(a1 - (b1 + b3), (ll)0);
    ll win2 = max(a2 - (b2 + b1), (ll)0);
    ll win3 = max(a3 - (b3 + b2), (ll)0);
    ll total_wins = win1 + win2 + win3;
    cout << total_wins;
    return 0;
}
