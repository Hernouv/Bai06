#include <bits/stdc++.h>
using namespace std;

struct Seq
{
    long long length;
    int u, v;
    int val;
    bool isBase;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Seq> seq(n + m + 1);

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        seq[i].isBase = true;
        seq[i].val = (int)x;
        seq[i].length = 1;
    }

    for (int i = n + 1; i <= n + m; i++)
    {
        int u_i, v_i;
        cin >> u_i >> v_i;
        seq[i].isBase = false;
        seq[i].u = u_i;
        seq[i].v = v_i;

        seq[i].length = seq[u_i].length + seq[v_i].length;
    }

    for (int _q = 0; _q < q; _q++)
    {
        int x;
        long long y;
        cin >> x >> y;

        while (!seq[x].isBase)
        {
            long long leftLength = seq[seq[x].u].length;
            if (y <= leftLength)
            {
                x = seq[x].u;
            }
            else
            {
                y = y - leftLength;
                x = seq[x].v;
            }
        }

        cout << seq[x].val << "\n";
    }

    return 0;
}
