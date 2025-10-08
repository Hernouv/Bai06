#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, v;

int find_gcd(int n1, int n2)
{
    while (n1 and n2)
    {
        if (n1 < n2)
            swap(n1, n2);
        n1 %= n2;
    }
    return max(n1, n2);
}

void not_main()
{
    while (cin >> a >> b >> c >> d >> v)
    {
        if (!c and !d)
        {
            if (a or b)
                cout << "NONE\n";
            else if (!a and !b)
                cout << "MULTIPLE\n";
            continue;
        }

        int t1 = a - c * v;
        int t2 = d * v - b;

        if (!t1 and t2)
        {
            cout << "NONE\n";
            continue;
        }

        if (!t1 and !t2)
        {
            cout << "MULTIPLE\n";
            continue;
        }

        if (t1 and !t2)
        {
            cout << "X = 0/1\n";
            continue;
        }

        if (t1 < 0)
            t1 = -t1, t2 = -t2;
        int abs_t1 = abs(t1), abs_t2 = abs(t2);
        int gcd = find_gcd(abs_t1, abs_t2);

        cout << "X = " << t2 / gcd << '/' << t1 / gcd << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("EQUATION.INP", "r"))
    {
        freopen("EQUATION.INP", "r", stdin);
        freopen("EQUATION.OUT", "w", stdout);
    }
    not_main();
    return 0;
}