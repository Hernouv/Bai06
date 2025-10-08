#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[100010];
pair<char, char> change_generalized[30];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CHGSTR.INP", "r"))
    {
        freopen("CHGSTR.INP", "r", stdin);
        freopen("CHGSTR.OUT", "w", stdout);
    }
    for (int i = 0; i < 26; ++i)
        change_generalized[i + 1] = {char('a' + i), 'A'};

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    char a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        for (int i = 1; i <= 26; ++i)
            if (change_generalized[i].second == a)
                change_generalized[i].second = b;

        if (change_generalized[a - 'a' + 1].second == 'A')
            change_generalized[a - 'a' + 1].second = b;
    }

    for (int i = 1; i <= n; ++i)
        if (change_generalized[s[i] - 'a' + 1].second != 'A')
            s[i] = change_generalized[s[i] - 'a' + 1].second;

    for (int i = 1; i <= n; ++i)
        cout << s[i];
    return 0;
}