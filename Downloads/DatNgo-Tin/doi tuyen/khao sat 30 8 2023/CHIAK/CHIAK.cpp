#include <bits/stdc++.h>
using namespace std;

int arr[1000001], mod, n, cnt = 0, r_0 = 0;
map<int, int> r_cnt;

void sub12()
{
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum = (sum + arr[j]) % mod;
            if (!sum)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}

void sub3()
{
    for (int i = 2; i <= n; ++i)
        arr[i] = (arr[i - 1] + arr[i]) % mod;
    sort(arr + 1, arr + n + 1);
    int start = 1, end = 1;
    while (start <= n and end <= n)
    {
        while (end <= n and arr[end] == arr[end + 1])
            end++;
        int sz = end - start + 1;
        if (sz == 1 and arr[end] == 0)
            cnt++;
        else
            cnt += sz * (sz - 1) / 2;
        end++;
        start = end;
    }
    cout << cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("CHIAK.INP", "r", stdin);
    // freopen("CHIAK.OUT", "w", stdout);
    cin >> n >> mod;
    arr[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        arr[i] %= mod;
    }
    sub12();
    return 0;
}
/*
void vanikomi(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        dp[i] = (dp[i - 1] + x + nm * k) % k;
    }
    sort(dp + 1, dp + n + 1);
    dp[n + 1] = nm;
    int d = 1;
    for(int i = 1; i <= n + 1; ++i){
        if(dp[i] != dp[i - 1]){
            res += d * (d - 1) / 2;
            d = 1;
        }else d++;
    }
    cout << res << '\n';
}
*/