#include <bits/stdc++.h>
#define taskname "hackathon"
#define int long long

using namespace std;

struct Student
{
    int a, b, sub;

    bool operator<(const Student &other) const
    {
        return (sub < other.sub);
    }
};

const int maxN = (int)(1e6);
const int inf = (int)(1e16);

int n, m, p, k, cur = 0, sum = 0, res = 0;
int G[maxN + 5], F[maxN + 5];
Student arr[maxN + 5];
priority_queue<int> pq;

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    cin >> m >> n >> p;
    k = m + n + p;
    for (int a, b, c, i = 1; i <= k; i++)
    {
        cin >> a >> b >> c;
        arr[i].a = a - c;
        arr[i].b = b - c;
        arr[i].sub = arr[i].a - arr[i].b;
        res += c;
    }
    sort(arr + 1, arr + 1 + k);
    for (int i = 1; i <= k; i++)
    {
        if (i <= m)
        {
            pq.push(arr[i].a);
            sum += arr[i].a;
            F[i] = sum;
        }
        else
        {
            pq.push(arr[i].a);
            sum += arr[i].a;
            sum -= pq.top();
            pq.pop();
            F[i] = sum;
        }
    }
    sum = 0;
    while (!pq.empty())
        pq.pop();
    for (int i = k; i >= 1; i--)
    {
        if (pq.size() < n)
        {
            pq.push(arr[i].b);
            sum += arr[i].b;
            G[i] = sum;
        }
        else
        {
            pq.push(arr[i].b);
            sum += arr[i].b;
            sum -= pq.top();
            pq.pop();
            G[i] = sum;
        }
    }
    cur = inf;
    for (int i = m + 1; i <= k - n; i++)
        cur = min(cur, F[i] + G[i + 1]);
    res += cur;
    cout << res;
}