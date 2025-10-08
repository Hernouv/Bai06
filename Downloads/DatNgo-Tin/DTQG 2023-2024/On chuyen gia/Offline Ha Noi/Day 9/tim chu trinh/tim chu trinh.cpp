#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[4] = {0, 1, 2, 3};

void swap_forPrint(int c, int b)
{
    if (a[1] == c)
    {
        if (a[2] == b)
            swap(a[1], a[2]);
        else
            swap(a[1], a[3]);
    }
    else if (a[2] == c)
    {
        if (a[1] == b)
            swap(a[1], a[2]);
        else
            swap(a[2], a[3]);
    }
    else
    {
        if (a[1] == b)
            swap(a[1], a[3]);
        else
            swap(a[2], a[3]);
    }
}

void print(int n, int m, int k)
{
    if (a[1] == 1)
    {
        if (a[2] == 2)
            cout << n << " " << m << " " << k << '\n';
        else
            cout << n << " " << k << ' ' << m << '\n';
    }
    else if (a[1] == 2)
    {
        if (a[2] == 1)
            cout << m << ' ' << n << ' ' << k << '\n';
        else
            cout << m << ' ' << k << ' ' << n << '\n';
    }
    else
    {
        if (a[2] == 1)
            cout << k << ' ' << n << ' ' << m << '\n';
        else
            cout << k << ' ' << m << ' ' << n << '\n';
    }
}

void not_main()
{
    cin >> n >> m >> k;
    if (n & 1 and m & 1 and k & 1)
    {
        cout << "No";
        return;
    }
    if (m + n + k == max({m, n, k}) + 2)
    {
        cout << "No";
        return;
    }

    cout << "Yes\n";
    if (!(m & 1))
    {
        swap(n, m);
        swap_forPrint(1, 2);
    }
    if (!(k & 1))
    {
        swap(n, k);
        swap_forPrint(1, 3);
    }
    cout << "1 1 1\n";
    for (int K = 1; K <= k; ++K)
    {
        if (K & 1)
        {
            for (int i = 2; i <= n; ++i)
                print(i, 1, K);
            for (int i = n; i >= 1; --i)
            {
                if (i & 1)
                    for (int j = m; j >= 2; --j)
                        print(i, j, K);
                else
                    for (int j = 2; j <= m; ++j)
                        print(i, j, K);
            }
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (i & 1)
                    for (int j = 2; j <= m; ++j)
                        print(i, j, K);
                else
                    for (int j = m; j >= 2; --j)
                        print(i, j, K);
            }
            for (int i = n; i >= 2; --i)
                print(i, 1, K);
        }
    }
    for (int i = k; i >= 1; --i)
        print(1, 1, i);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}