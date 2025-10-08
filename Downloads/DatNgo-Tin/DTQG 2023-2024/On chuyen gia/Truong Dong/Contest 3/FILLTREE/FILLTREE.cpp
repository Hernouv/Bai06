#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[200010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return 0;
}