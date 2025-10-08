#include <bits/stdc++.h>
using namespace std;

string inp;

void not_main()
{
    getline(cin, inp);
    int sz = inp.size();
    inp += " aaaaa";
    int i = 0;
    while (i < sz)
    {
        bool detected = false;
        if (inp[i] == 'c' and i <= sz - 6)
        {
            string tmp = "";
            for (int j = i; j <= i + 6; ++j)
                tmp += inp[j];
            string tmp2 = tmp;
            for (int j = i + 7; j <= i + 12; ++j)
                tmp2 += inp[j];

            if (tmp2 == "con ong ngoan")
            {
                cout << "con ong ngoan";
                i += 13;
                detected = true;
            }
            else if (tmp == "con ong")
            {
                cout << "con ong ngoan";
                i += 7;
                detected = true;
            }
        }
        if (!detected)
        {
            cout << inp[i];
            ++i;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DBEE.INP", "r"))
    {
        freopen("DBEE.INP", "r", stdin);
        freopen("DBEE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}