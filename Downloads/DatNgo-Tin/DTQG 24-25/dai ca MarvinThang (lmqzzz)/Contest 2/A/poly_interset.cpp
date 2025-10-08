#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long x, y;
};

void proc()
{
    int a, b, c1, c2;
    cin >> a >> b >> c1 >> c2;
    int k;
    cin >> k;
    vector<Point> cho(k + 1);
    for (int i = 0; i < k; i++)
    {
        cin >> cho[i].x >> cho[i].y;
    }
    cho[k] = {cho[0].x, cho[0].y};

    for (int i = 0; i < k; ++i)
    {
        long long val1 = 1LL * a * cho[i].x + 1LL * b * cho[i].y;
        long long val2 = 1LL * a * cho[i + 1].x + 1LL * b * cho[i + 1].y;

        int state1, state2;
        int minc = min(c1, c2), maxc = max(c1, c2);

        if (val1 <= minc)
            state1 = -1;
        else if (minc < val1 && val1 < maxc)
            state1 = 0;
        else if (val1 >= maxc)
            state1 = 1;

        if (val2 <= minc)
            state2 = -1;
        else if (minc < val2 && val2 < maxc)
            state2 = 0;
        else if (val2 >= maxc)
            state2 = 1;

        int state_sum = state1 + state2;
        // cerr << state_sum << '\n';
        if (state_sum == 0 or state_sum == -1 or state_sum == 1)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int test;
    cin >> test;

    while (test--)
    {
        proc();
    }
    return 0;
}
