#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5 + 5;

void not_main()
{
    int N, L;
    cin >> N >> L;

    vector<int> W(N + 5), H(N + 5);
    vector<ll> DP(N + 5);

    vector<int> S;
    int rsz = 0;
    int wsum = 0;
    DP[0] = 0;
    multiset<ll> bst;
    int j = 1;

    for (int i = 1; i <= N; i++)
    {
        cin >> H[i] >> W[i];

        S.push_back(1);
        rsz++;

        while (rsz > 1 and H[i - S[rsz - 1]] <= H[i])
        {
            ll val_to_remove = 1LL * (H[i - S[rsz - 1]]) + DP[i - S[rsz - 1] - S[rsz - 2]];
            auto it = bst.find(val_to_remove);
            if (it != bst.end())
                bst.erase(it);

            S[rsz - 2] += S[rsz - 1];
            S.pop_back();
            rsz--;
        }

        bst.insert((H[i]) + DP[i - S.back()]);

        wsum += W[i];

        while (wsum > L)
        {
            wsum -= W[j];

            ll val_to_remove = 1LL * (H[j + S[0] - 1]) + DP[j - 1];
            auto it = bst.find(val_to_remove);
            if (it != bst.end())
                bst.erase(it);

            S[0]--;
            if (S[0] == 0)
            {
                S.erase(S.begin());
                rsz--;
            }
            else
                bst.insert(1LL * (H[j + S[0]]) + DP[j]);
            j++;
        }
        DP[i] = *bst.begin();
    }

    cout << DP[N];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BOOKS.inp", "r"))
    {
        freopen("BOOKS.inp", "r", stdin);
        freopen("BOOKS.out", "w", stdout);
    }
    int test = 1;
    cin >> test;
    while (test--)
    {
        not_main();
        cout << '\n';
    }
    return 0;
}
