#include <bits/stdc++.h>
using namespace std;

#define nmax 1005
#define fi first
#define se second

typedef long long ll;
#define int ll
typedef pair<int, int> ii;

ii a[nmax], b[nmax];
int dp[nmax][nmax], dpcont[nmax][nmax];
vector<int> pos[30];
int cnt = 0, lena = 0, lenb = 0;
string s;

void not_main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'a' and s[i] <= 'z')
        {
            if (cnt)
            {
                a[lena].se = cnt;
                a[++lena].fi = s[i] - 'a' + 1;
                cnt = 0;
            }
            else
                a[++lena].fi = s[i] - 'a' + 1;
        }
        else
            cnt = cnt * 10 + (s[i] - '0');
    a[lena].se = cnt;

    cnt = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'a' and s[i] <= 'z')
        {
            if (cnt)
            {
                b[lenb].se = cnt;
                b[++lenb].fi = s[i] - 'a' + 1;
                cnt = 0;
            }
            else
                b[++lenb].fi = s[i] - 'a' + 1;
        }
        else
            cnt = cnt * 10 + (s[i] - '0');
    b[lenb].se = cnt;

    cnt = 0;
    for (int i = 1; i <= lenb; i++)
        pos[b[i].fi].push_back(i);
    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
        {
            if (a[i].fi != b[j].fi)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                continue;
            }
            int ch_a = a[i].fi, pointer;
            int suma = 0, sumb = b[j].se;
            for (int k = 0; k < pos[ch_a].size(); k++)
                if (pos[ch_a][k] == j)
                {
                    pointer = k;
                    break;
                }
            for (int k = i; k; k--)
            {
                int cur_ch_a = a[k].fi;
                if (cur_ch_a == ch_a)
                    suma += a[k].se;
                while (pointer and sumb < suma)
                {
                    dp[i][j] = max(dp[i][j], dp[k - 1][pos[ch_a][pointer] - 1] + sumb);
                    pointer--;
                    sumb += b[pos[ch_a][pointer]].se;
                }
                dp[i][j] = max(dp[i][j], dp[k - 1][pos[ch_a][pointer] - 1] + min(suma, sumb));
            }
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    cout << dp[lena][lenb] << '\n';

    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
        {
            if (a[i].fi != b[j].fi)
                continue;
            if (a[i].se == b[j].se)
                dpcont[i][j] = dpcont[i - 1][j - 1] + a[i].se;
            else
                dpcont[i][j] = min(a[i].se, b[j].se);
        }
    int rescont = 0;
    for (int i = 0; i <= lena; i++)
        for (int j = 0; j <= lenb; j++)
        {
            if (a[i + 1].fi == b[j + 1].fi)
                rescont = max(rescont, dpcont[i][j] + min(a[i + 1].se, b[j + 1].se));
            else
                rescont = max(rescont, dpcont[i][j]);
        }
    cout << rescont;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}