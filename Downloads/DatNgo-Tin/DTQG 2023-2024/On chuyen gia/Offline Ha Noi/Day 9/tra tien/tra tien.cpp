#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
set<ll> banknotes;
ll a[100010];
ll V;

void input()
{
    cin >> n;
    int temp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        banknotes.insert(temp);
    }
    int it = 0;
    for (ll x : banknotes)
    {
        a[++it] = x;
    }
    cin >> V;
}

void not_main()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}