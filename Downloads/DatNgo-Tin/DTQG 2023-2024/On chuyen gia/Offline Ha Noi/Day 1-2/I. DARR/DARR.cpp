#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010], l[100010], r[100010];
int res[100010];
bool check[100010];
stack<int> st[2];
int chrono_run = 1;

void calc(stack<int> &in)
{
    stack<int> temp;
    while (!in.empty())
    {
        int x = in.top();
        in.pop();
        res[x] = chrono_run;

        if (!check[l[x]] and l[x] != 1)
            temp.push(l[x]);
        if (!check[r[x]] and r[x] != n)
            temp.push(r[x]);
        l[r[x]] = l[x];
        r[l[x]] = r[x];
        check[l[x]] = check[r[x]] = true;
    }

    while (!temp.empty())
    {
        int x = temp.top();
        temp.pop();
        if (a[x] < a[l[x]] and a[x] < a[r[x]])
            st[1 - (chrono_run & 1)].push(x);
        else
            check[x] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i < n; ++i)
    {
        if (a[i] < a[i - 1] and a[i] < a[i + 1])
            st[1].push(i);
        l[i] = i - 1;
        r[i] = i + 1;
    }

    while (!st[chrono_run & 1].empty())
    {
        calc(st[chrono_run & 1]);
        ++chrono_run;
    }

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';

    return 0;
}