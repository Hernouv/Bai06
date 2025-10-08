#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> l2;
#define fi first
#define se second

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

struct project
{
    long long start;
    long long finish;
    long long pay;

    bool operator<(const project x) const
    {
        return (finish < x.finish);
    }
};

void not_main()
{
    int n;
    cin >> n;
    vector<project> projects(n);
    for (int i = 0; i < n; ++i)
        cin >> projects[i].start >> projects[i].finish >> projects[i].pay;
    sort(projects.begin(), projects.end());
    set<l2> proc;
    proc.emplace(0, 0);
    long long res = 0;
    for (project it : projects)
    {
        auto t = proc.lower_bound({it.start, -1});
        --t;
        maximize(res, it.pay + t->se);
        proc.emplace(it.finish, res);
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}