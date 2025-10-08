#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e3 + 10;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

int n;
long long d;
long long a[nmax];
bool picked[nmax];

struct custom
{
    long long sum;
    int i1, i2;
};
vector<custom> score_pair;

vector<custom> proc;
int curr_proc_size = 0;
vector<int> s_length;

bool cmp(custom a, custom b)
{
    return (a.sum < b.sum or (a.sum == b.sum and a.i1 < b.i1) or (a.sum == b.sum and a.i1 == b.i1 and a.i2 > b.i2));
    // return (a.i1 < b.i1 or (a.i1 == b.i1 and a.i2 > b.i2) or (a.i1 == b.i1 and a.i2 == b.i2 and a.sum < b.sum));
}

void not_main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << ' ';
    // cout << '\n';

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            score_pair.push_back({a[i] + a[j], i, j});
    sort(score_pair.begin(), score_pair.end(), cmp);

    for (custom x : score_pair)
        cout << x.sum << ' ' << x.i1 << ' ' << x.i2 << '\n';
    cout << '\n';

    // int res = 0;

    // for (custom x : score_pair)
    // {
    //     int iter = 0;
    //     for (; iter < curr_proc_size; ++iter)
    //     {
    //         if (abs(proc[iter].sum - x.sum) <= d and x.i1 > proc[iter].i1 and x.i2 < proc[iter].i2)
    //         {
    //             proc[iter] = x;
    //             ++s_length[iter];
    //             break;
    //         }
    //     }
    //     if (iter == curr_proc_size)
    //     {
    //         proc.push_back(x);
    //         s_length.push_back(1);
    //         ++curr_proc_size;
    //     }
    // }

    // for (int x : s_length)
    //     maximize(res, x);
    // cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PAIR.INP", "r"))
    {
        freopen("PAIR.INP", "r", stdin);
        freopen("PAIR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}