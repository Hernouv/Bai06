#include <bits/stdc++.h>
using namespace std;

int cnt_occurs(const string &text, const string &pattern)
{
    int n = text.size(), m = pattern.size();
    if (m > n)
        return 0;

    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = lps[j - 1];
        if (pattern[i] == pattern[j])
            lps[i] = ++j;
    }

    int cnt = 0;
    j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && text[i] != pattern[j])
            j = lps[j - 1];
        if (text[i] == pattern[j])
            ++j;
        if (j == m)
        {
            ++cnt;
            j = lps[j - 1];
        }
    }
    return cnt;
}

void not_main()
{
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    vector<string> strings(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strings[i];
    }

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, k;
            cin >> x >> k;
            v[x - 1] = k;
        }
        else if (type == 2)
        {
            string s;
            cin >> s;
            long long result = 0;
            for (int j = 0; j < n; ++j)
            {
                int occurs = cnt_occurs(strings[j], s);
                result += static_cast<long long>(occurs) * v[j];
            }
            cout << result << "\n";
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("function.inp", "r"))
    {
        freopen("function.inp", "r", stdin);
        freopen("function.out", "w", stdout);
    }
    not_main();
    return 0;
}
