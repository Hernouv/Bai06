#include <bits/stdc++.h>
using namespace std;

int a[1000001], bacc[1000001], fronn[1000001];
stack<int> backlarge, frontlarge;
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while(!backlarge.empty() and a[i] >= a[backlarge.top()]) backlarge.pop();
        bacc[i] = (backlarge.empty() ? 0 : backlarge.top());
        backlarge.push(i);
    }
    for (int i = n; i >= 1; --i)
    {
        while(!frontlarge.empty() and a[i] >= a[frontlarge.top()]) frontlarge.pop();
        fronn[i] = (frontlarge.empty() ? 0 : frontlarge.top());
        frontlarge.push(i);
    }
    for (int i = 1; i <= n; ++i) cout << bacc[i] << ' ' << fronn[i] << '\n';
    return 0;
}
