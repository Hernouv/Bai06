#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define whole(__) __.begin(), __.end()

const int nmax = 4e5 + 5;

int n;
int x[nmax], a[nmax], b[nmax];

void sub1()
{
    cout << 1 << ' ' << n;
    return;
}

void sub2()
{
    int res = -1;
    int cnt = 0;
    stack<int> xa;
    xa.push(x[1] - a[1]);
    for (int i = 2; i <= n; ++i)
    {
        int tnum = x[i] - a[i];
        if (tnum != xa.top())
        {
            int Sz = xa.size();
            if (maximize(res, Sz))
            {
                res = Sz;
                cnt = 1;
            }
            else if (res == Sz)
                ++cnt;

            while (!xa.empty())
                xa.pop();
        }
        xa.push(tnum);
    }

    int Sz = xa.size();
    if (maximize(res, Sz))
    {
        res = Sz;
        cnt = 1;
    }
    else if (res == Sz)
        ++cnt;

    while (!xa.empty())
        xa.pop();

    cout << res << ' ' << cnt;
    return;
}

vector<int> listL, listR;
int res3 = 0, cnt3 = 0;

void proc3(int L, int R)
{
    // cerr << L << ' ' << R << ":\n";
    int tsz = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == L or b[i] == R)
        {
            // cerr << a[i] << ' ' << b[i] << '\n';
            ++tsz;
        }
        else if (tsz)
        {
            // cerr << tsz << '\n';
            if (maximize(res3, tsz))
            {
                // cerr << L << ' ' << R << '\n';
                cnt3 = 1;
            }
            else if (res3 == tsz)
            {
                // cerr << L << ' ' << R << '\n';
                ++cnt3;
            }
            tsz = 0;
        }
    }

    if (maximize(res3, tsz))
    {
        // cerr << L << ' ' << R << '\n';
        cnt3 = 1;
    }
    else if (res3 == tsz)
    {
        // cerr << L << ' ' << R << '\n';
        ++cnt3;
    }
}

void sub3()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] = x[i] - a[i];
        b[i] = x[i] + b[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        listL.push_back(a[i]);
        listR.push_back(b[i]);
    }

    sort(whole(listL));
    listL.erase(unique(whole(listL)), listL.end());
    sort(whole(listR));
    listR.erase(unique(whole(listR)), listR.end());

    // listL.push_back(-1e9);
    // listR.push_back(-1e9);
    // for (int L : listL)
    //     cerr << L << ' ';
    // cerr << '\n';
    // for (int R : listR)
    //     cerr << R << ' ';

    for (int L : listL)
        for (int R : listR)
        {
            proc3(L, R);
            // cerr << '\n';
        }

    cout << res3 << ' ' << cnt3;
    return;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> a[i] >> b[i];
    }

    bool s1a = true, s1b = true;
    for (int i = 2; i <= n; ++i)
        if (a[i] != a[i - 1])
        {
            s1a = false;
            break;
        }
    for (int i = 2; i <= n; ++i)
        if (b[i] != b[i - 1])
        {
            s1b = false;
            break;
        }
    if (s1a and s1b)
    {
        sub1();
        return;
    }
    if (s1b)
    {
        sub2();
        return;
    }
    if (n <= 300)
    {
        sub3();
        return;
    }
    // AC: for element i, check how many consecutive elements to the right share L or R.
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ROADSIGNS.INP", "r"))
    {
        freopen("ROADSIGNS.INP", "r", stdin);
        freopen("ROADSIGNS.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
