#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> compute_knapsack(const vector<pair<ll, int>> &items, int exclude = -1)
{
    ll max_value = 0;
    for (int i = 0; i < items.size(); ++i)
    {
        if (i != exclude)
        {
            max_value += items[i].second;
        }
    }

    vector<ll> dp(max_value + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < items.size(); ++i)
    {
        if (i == exclude)
            continue;
        ll wi = items[i].first;
        int ci = items[i].second;
        for (ll v = max_value; v >= ci; --v)
        {
            if (dp[v - ci] != LLONG_MAX and dp[v - ci] + wi < dp[v])
            {
                dp[v] = dp[v - ci] + wi;
            }
        }
    }

    return dp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    ll W, H;
    cin >> N >> W >> H;

    vector<pair<ll, int>> items(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> items[i].first >> items[i].second;
    }
    vector<ll> dp_all = compute_knapsack(items, -1);

    ll max_without_extra = 0;
    for (ll v = 0; v < dp_all.size(); ++v)
    {
        if (dp_all[v] <= W)
        {
            max_without_extra = max(max_without_extra, v);
        }
    }

    ll answer = max_without_extra;

    for (int j = 0; j < N; ++j)
    {
        ll wj = items[j].first;
        int cj = items[j].second;
        if (wj > H)
            continue;

        vector<ll> dp_excl = compute_knapsack(items, j);

        ll max_excl = 0;
        for (ll v = 0; v < dp_excl.size(); ++v)
        {
            if (dp_excl[v] <= W)
            {
                max_excl = max(max_excl, v);
            }
        }

        ll total = max_excl + cj;
        answer = max(answer, total);
    }

    cout << answer;
    return 0;
}
