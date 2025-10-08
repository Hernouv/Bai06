#include <bits/stdc++.h>
using namespace std;

stack<int> backlarge, frontlarge;
pair<int,int> cow[50001];
bool bacc[50001], fronn[50001];
int n,d, cnt = 0;

bool byfirst(const pair<int,int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(bacc, false, sizeof(bacc));
    memset(fronn, false, sizeof(fronn));
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        int pos, h;
        cin >> pos >> h;
        cow[i] = {pos, h};
    }
    sort(cow + 1, cow + n + 1, byfirst);
    for (int i = 1; i <= n; ++i)
    {
        int temp_h = 2 * cow[i].second;
        while (!backlarge.empty() and temp_h > cow[backlarge.top()].second) backlarge.pop();
        if (!backlarge.empty())
            if (cow[i].first - cow[backlarge.top()].first <= d)
                bacc[i] = true;
        backlarge.push(i);
    }
    for (int i = n; i >= 1; --i)
    {
        int temp_h = 2 * cow[i].second;
        while (!frontlarge.empty() and temp_h > cow[frontlarge.top()].second) frontlarge.pop();
        if (!frontlarge.empty())
            if (cow[frontlarge.top()].first - cow[i].first <= d)
                fronn[i] = true;

        frontlarge.push(i);
    }
    for (int i = 1; i <= n; ++i)
        if (bacc[i] and fronn[i]) cnt++;
    cout << cnt;
    return 0;
}
