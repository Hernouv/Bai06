#include <bits/stdc++.h>
using namespace std;

vector<int> edge;
vector<int> sq;
int n;
int acute_cnt = 0, square_cnt = 0, obtuse_cnt = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("CAU5.INP", "r", stdin);
    // freopen("CAU5.OUT", "w", stdout);
    cin >> n;
    int l;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l;
        edge.push_back(l);
    }
    sort(edge.begin(), edge.end());
    for (int x : edge)
        sq.push_back(x * x);
    for (int i = 0; i < n - 2; ++i)
        for (int j = i + 1; j < n - 1; ++j)
        {
            if (edge[i] + edge[j] <= edge[j + 1])
                continue;
            int sq_lo, sq_hi;
            int lim_hi = lower_bound(edge.begin() + j, edge.end(), edge[j] + edge[i]) - edge.begin() - 1;
            int acute_hi = lower_bound(sq.begin() + j, sq.end(), sq[i] + sq[j]) - sq.begin() - 1;
            sq_lo = acute_hi + 1;
            if (sq[sq_lo] != sq[i] + sq[j])
                sq_lo = -1;
            if (acute_hi < j)
                acute_hi = -1;

            int obtuse_lo = upper_bound(sq.begin() + j, sq.end(), sq[i] + sq[j]) - sq.begin();
            sq_hi = obtuse_lo - 1;
            if (sq[sq_hi] != sq[i] + sq[j])
                sq_hi = -1;
            if (obtuse_lo > lim_hi or obtuse_lo == n)
                obtuse_lo = -1;

            if (acute_hi != -1)
                acute_cnt += acute_hi - j;
            if (obtuse_lo != -1)
                obtuse_cnt += lim_hi - obtuse_lo + 1;
            if (sq_lo != -1 and sq_hi != -1)
                square_cnt += sq_hi - sq_lo + 1;
        }
    cout << '\n'
         << acute_cnt << ' ' << square_cnt << ' ' << obtuse_cnt;
    return 0;
}