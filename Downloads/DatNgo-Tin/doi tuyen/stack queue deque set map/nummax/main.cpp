#include <bits/stdc++.h>
using namespace std;

long long L[100001], R[100001], a[100001], j = 0;
stack<long long> forw, backw;
vector<long long> posb;
long long cnt = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (!forw.empty() and a[i] >= a[forw.top()]) forw.pop();
        L[i] = (forw.empty() ? 1 : forw.top() + 1);
        L[i] = max(L[i], j + 1);
        if (a[i] == b) j = i;
        forw.push(i);
    }
    for (int i = n; i >= 1; --i)
    {
        while (!backw.empty() and a[i] >= a[backw.top()]) backw.pop();
        R[i] = (backw.empty() ? n : backw.top() - 1);
        backw.push(i);
    }
    for (int i = 1; i <= n; ++i) cout << L[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i)
        if (a[i] == b)
            cnt += (i - L[i] + 1) * (R[i] - i + 1);
    cout << cnt;
    return 0;
}
