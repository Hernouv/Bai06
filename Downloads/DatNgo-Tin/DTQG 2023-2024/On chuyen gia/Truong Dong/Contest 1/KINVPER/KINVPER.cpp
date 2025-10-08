#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void sub1()
{
    int res = 0;
    int s1[n];
    for (int i = 0; i < n; ++i)
        s1[i] = i + 1;
    do
    {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (s1[i] > s1[j])
                    cnt++;
        if (cnt == k)
        {
            for (int i = 0; i < n; ++i)
                cout << s1[i] << ' ';
            cout << '\n';
            res++;
        }
    } while (next_permutation(s1, s1 + n));
    cout << res << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("KINVPER.INP", "r"))
    {
        freopen("KINVPER.INP", "r", stdin);
        freopen("KINVPER.OUT", "w", stdout);
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n <= 8 and k <= 8)
            sub1();
    }

    return 0;
}