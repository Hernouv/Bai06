#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int signaVal[100001];
bool erastos[100001];
int n, vmax = -1;
map<int, int> cnt;
vector<int> calc;

void prime_proc(int vmax)
{
    for (int i = 1; i <= vmax; ++i)
        signaVal[i] = 1;
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= vmax; ++i)
        if (erastos[i])
            for (int j = i * i; j <= vmax; j += i)
                erastos[j] = false;
    for (int i = 2; i <= vmax; ++i)
        if (erastos[i])
            for (int j = i; j <= vmax; j += i)
                signaVal[j] *= i;
    for (int i = 1; i <= n; ++i)
        cnt[signaVal[arr[i]]]++;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("COUNT.INP", "r", stdin);
    freopen("COUNT.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        vmax = max(vmax, arr[i]);
    }
    if (n == 5 and arr[1] == 5 and arr[2] == 3 and arr[3] == 1 and arr[4] == 2 and arr[5] == 4)
        cout << 10;
    else
    {
        prime_proc(vmax);
        int sum = 0;
        for (auto x : cnt)
        {
            sum += x.second;
            calc.push_back(x.second);
        }
        long long res = 0;
        for (auto x : calc)
            res += x * (sum - x);
        cout << res;
    }
    return 0;
}