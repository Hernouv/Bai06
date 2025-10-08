#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h;
    cin >> h;
    vector<ll> xi(h);
    vector<ll> neg;
    vector<ll> pos;
    for (int i = 0; i < h; i++)
    {
        cin >> xi[i];
        if (xi[i] < 0)
        {
            neg.push_back(xi[i]);
        }
        else
        {
            pos.push_back(xi[i]);
        }
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    int n_neg = neg.size();
    int n_pos = pos.size();
    vector<ll> prefix_neg(n_neg + 1, 0);
    for (int i = 0; i < n_neg; i++)
        prefix_neg[i + 1] = prefix_neg[i] + (-neg[i]);
    vector<ll> prefix_pos(n_pos + 1, 0);
    for (int i = 0; i < n_pos; i++)
        prefix_pos[i + 1] = prefix_pos[i] + pos[i];

    ll sum_neg_total = prefix_neg[n_neg];
    ll sum_pos_total = prefix_pos[n_pos];

    ll min_total = sum_neg_total + sum_pos_total;

    for (int i = 0; i < n_neg; i++)
    {
        ll A = neg[i];
        ll sum_before_A = prefix_neg[i + 1];
        ll sum_after_A = (prefix_neg[n_neg] - prefix_neg[i + 1]) - ((-A) * (n_neg - (i + 1)));
        ll total_neg = sum_before_A + sum_after_A;
        ll total_time = total_neg + sum_pos_total;
        if (total_time < min_total)
        {
            min_total = total_time;
        }
    }

    for (int i = 0; i < n_pos; i++)
    {
        ll A = pos[i];
        ll sum_before_A = prefix_pos[i];
        ll sum_after_A = (prefix_pos[n_pos] - prefix_pos[i]) - (A * (ll)(n_pos - i));
        ll total_pos = sum_before_A + sum_after_A;
        ll total_time = total_pos + sum_neg_total;
        if (total_time < min_total)
        {
            min_total = total_time;
        }
    }

    cout << min_total;
}
