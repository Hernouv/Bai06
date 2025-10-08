#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void dnc(int g, int l, int r, int opt_l, int opt_r, const vector<ll> &dp_prev, vector<ll> &dp_current, const vector<ll> &S)
{
    if (l > r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    int best_k = opt_l;
    ll best_cost = INF;
    int upper_k = min(m - 1, opt_r);
    for (int k = opt_l; k <= upper_k; k++)
    {
        ll cost = dp_prev[k] + (m - k) * (S[m] - S[k]);
        if (cost < best_cost)
        {
            best_cost = cost;
            best_k = k;
        }
    }
    dp_current[m] = best_cost;
    dnc(g, l, m - 1, opt_l, best_k, dp_prev, dp_current, S);
    dnc(g, m + 1, r, best_k, opt_r, dp_prev, dp_current, S);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll L, G;
    cin >> L >> G;
    vector<ll> C(L + 1, 0);
    for (int i = 1; i <= L; i++)
        cin >> C[i];
    vector<ll> S(L + 1, 0);
    for (int i = 1; i <= L; i++)
        S[i] = S[i - 1] + C[i];
    if (G > L)
    {
        G = L;
    }
    if (G == L)
    {
        cout << S[L];
        return 0;
    }
    vector<ll> dp_prev(L + 1, 0);
    for (int i = 1; i <= L; i++)
        dp_prev[i] = i * S[i];
    vector<ll> dp_current(L + 1, INF);
    for (int g = 2; g <= G; g++)
    {
        fill(dp_current.begin(), dp_current.end(), INF);
        dnc(g, g, L, g - 1, L - 1, dp_prev, dp_current, S);
        dp_prev.swap(dp_current);
    }
    cout << dp_prev[L];
}
