#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define loop(_name, st, en) for (int _name = st; _name <= en; ++_name)

const int nmax = 1e3 + 5;

int n, k, m;
int vocal[nmax];
bool match_vocal[7][7], match_word[nmax][nmax], beauty[nmax], can_start_with[nmax];
ll ans = 0;

void subtask_proc(int len, int word, int s_len, int s_sum, int s_match, int prev_end, ll res)
{
    ans = max(ans, res);
    if (!beauty[word] and !s_len)
        return;
    if (len == m)
        return;

    if (!s_len)
    {
        s_sum += k;
        for (int i = 1; i <= n; ++i)
        {
            if (can_start_with[i])
            {
                subtask_proc(len + 1, i, 1, s_sum, s_match, prev_end, res);
                if (beauty[i] == true and match_vocal[vocal[prev_end]][vocal[i]] == true)
                {
                    s_match++;
                }
                ll new_res = 1LL * s_sum * s_match;
                subtask_proc(len + 1, i, 0, s_sum, s_match, i, new_res);
            }
        }
        return;
    }

    s_sum += (k - s_len);
    for (int i = 1; i <= n; ++i)
        if (match_word[word][i])
        {
            subtask_proc(len + 1, i, s_len + 1, s_sum, s_match, prev_end, res);
            if (beauty[i] == true and match_vocal[vocal[prev_end]][vocal[i]] == true)
            {
                s_match++;
            }
            ll new_res = 1LL * s_sum * s_match;
            subtask_proc(len + 1, i, 0, s_sum, s_match, i, new_res);
        }
}

void not_main()
{
    cin >> n >> k >> m;
    ans = 0;
    for (int i = 1; i <= n; ++i)
        cin >> vocal[i];
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 6; ++j)
            cin >> match_vocal[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> match_word[i][j];
        cin >> beauty[i];
    }
    for (int i = 1; i <= n + 1; ++i)
        cin >> can_start_with[i];

    for (int i = 1; i <= n; ++i)
        if (can_start_with[i])
        {
            subtask_proc(1, i, 1, k, 0, 0, 0);
            subtask_proc(1, i, 0, k, 0, i, 0);
        }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("WORD.INP", "r"))
    {
        freopen("WORD.INP", "r", stdin);
        freopen("WORD.OUT", "w", stdout);
    }
    not_main();
    return 0;
}