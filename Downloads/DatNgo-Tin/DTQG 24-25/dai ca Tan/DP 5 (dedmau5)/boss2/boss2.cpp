#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(__) __.begin(), __.end()

const ll INF64 = ll(1e18);

const int nmax = 2e5 + 5;
vector<int> cards[nmax][4];
ll dp[nmax][10];
int n;
ll dp2[4][2];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BOSS2.INP", "r"))
    {
        freopen("BOSS2.INP", "r", stdin);
        freopen("BOSS2.OUT", "w", stdout);
    }

    for (int i = 0; i < nmax; i++)
        for (int j = 0; j < 10; j++)
            dp[i][j] = -INF64;
    dp[0][0] = 0;
    cin >> n;
    for (int i = 0, k; i < n; i++)
    {
        cin >> k;
        for (int j = 0, c, d; j < k; j++)
        {
            cin >> c >> d;
            cards[i][c].push_back(d);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int s = (j == 1 ? 3 : 1);
            sort(cards[i][j].begin(), cards[i][j].end());
            reverse(cards[i][j].begin(), cards[i][j].end());
            while (cards[i][j].size() > s)
                cards[i][j].pop_back();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 2; k++)
                dp2[j][k] = -INF64;
        dp2[0][0] = 0;
        vector<ii> cur;
        for (int j = 1; j <= 3; j++)
            for (auto x : cards[i][j])
                cur.push_back(make_pair(j, x));
        sort(whole(cur));
        do
        {
            int mana = 3;
            ll score = 0;
            ll mx = 0;
            int cnt = 0;
            for (auto x : cur)
            {
                cnt++;
                if (mana < x.fi)
                    break;
                mana -= x.fi;
                mx = max(mx, ll(x.se));
                score += x.se;
                dp2[cnt][0] = max(dp2[cnt][0], score);
                dp2[cnt][1] = max(dp2[cnt][1], score + mx);
            }
        } while (next_permutation(cur.begin(), cur.end()));
        for (int j = 0; j < 10; j++)
            for (int k = 0; k <= 3; k++)
            {
                int nxt = (j + k) % 10;
                int f = (j + k >= 10 ? 1 : 0);
                dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + dp2[k][f]);
            }
    }
    ll ans = 0;
    for (int i = 0; i <= 9; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}