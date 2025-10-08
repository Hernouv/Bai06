#include <bits/stdc++.h>
using namespace std;

int t;
string inp;
int encrypted[55];
int decode[55];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("cipher.inp", "r"))
    {
        freopen("cipher.inp", "r", stdin);
        freopen("cipher.out", "w", stdout);
    }

    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> inp;
        if (inp.size() % 2)
            cout << "AMBIGUOUS";
        else
        {
            int sz = inp.size();
            for (int i = 0; i <= sz; ++i)
                decode[i] = -1;
            for (int i = 0; i < sz; ++i)
                encrypted[i + 1] = inp[i] - 'A';

            decode[2] = encrypted[1];
            decode[sz - 1] = encrypted[sz];

            for (int i = 4; i <= sz; i += 2)
                decode[i] = (encrypted[i - 1] - decode[i - 2] + 26) % 26;
            for (int i = sz - 3; i >= 1; i -= 2)
                decode[i] = (encrypted[i + 1] - decode[i + 2] + 26) % 26;

            for (int i = 1; i <= sz; ++i)
                cout << char(decode[i] + 'A');
        }
        cout << '\n';
    }
    return 0;
}