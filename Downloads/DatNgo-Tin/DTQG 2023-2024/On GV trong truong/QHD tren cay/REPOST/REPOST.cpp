#include <bits/stdc++.h>
using namespace std;

int n, res = 1;
string a, b, c;
map<string, int> graph;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("REPOST.INP", "r"))
    {
        freopen("REPOST.INP", "r", stdin);
        freopen("REPOST.OUT", "w", stdout);
    }

    graph["polycarp"] = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        for (int j = 0; j < a.size(); ++j)
            a[j] = tolower(a[j]);
        for (int j = 0; j < c.size(); ++j)
            c[j] = tolower(c[j]);
        graph[a] = graph[c] + 1;
        res = max(res, graph[a]);
    }
    cout << res;
    return 0;
}
