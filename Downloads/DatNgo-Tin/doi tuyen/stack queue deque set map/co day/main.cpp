#include <bits/stdc++.h>
using namespace std;

stack<unsigned long long> scan;
unsigned long long a[1000002];
unsigned long long cost = 0;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[n + 1] = 1000000007;
    scan.push(a[0]);
    for (int i = 1; i <= n + 1; ++i)
    {
        while (!scan.empty() and a[i] >= scan.top())
        {
            scan.pop();
            if (!scan.empty()) cost += min(a[i], scan.top());
        }
        scan.push(a[i]);
    }
    cout << cost - 1000000007;
    return 0;
}
