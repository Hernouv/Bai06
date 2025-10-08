#include <bits/stdc++.h>
using namespace std;

int n;
int rq_type;
// int perm[20];
long long ans1, perm_th;

long long facts[20];
void set_factorial()
{
    facts[0] = 1;
    for (int i = 1; i < 20; ++i)
        facts[i] = facts[i - 1] * i;
}

void rq_type1()
{
    int perm[20];
    for (int i = 1; i <= n; ++i)
        cin >> perm[i];

    // vector<int> num;
    // for (int i = 0; i <= n; ++i)
    //     num.push_back(i);

    for (int i = 1; i <= n; ++i)
    {
        ans1 += (perm[i] - 1) * facts[n - i];
        for (int j = i + 1; j <= n; ++j)
            perm[j] -= (perm[j] > perm[i]);
        // num.erase(num.begin() + perm[i]);
        //  cout << ans1 << '\n';
    }

    cout << ans1 + 1;
    ans1 = 0;
    return;
}

void rq_type2()
{
    cin >> perm_th;

    vector<int> num;
    for (int i = 0; i <= n; ++i)
        num.push_back(i);

    int perm[20];
    int it = 1;
    while (it <= n)
    {
        int t_pos = perm_th / facts[n - it];
        if (perm_th % facts[n - it])
            ++t_pos;
        perm[it] = num[t_pos];
        num.erase(num.begin() + t_pos);
        perm_th -= (t_pos - 1) * facts[n - it];
        ++it;
    }

    for (int i = 1; i <= n; ++i)
        cout << perm[i] << ' ';
    return;
}

void not_main()
{
    set_factorial();

    cin >> n;
    while (cin >> rq_type)
    {
        if (rq_type == 1)
        {
            rq_type1();
            cout << '\n';
        }
        else if (rq_type == 2)
        {
            rq_type2();
            cout << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("perm.inp", "r"))
    {
        freopen("perm.inp", "r", stdin);
        freopen("perm.out", "w", stdout);
    }
    not_main();
    return 0;
}