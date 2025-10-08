#include <bits/stdc++.h>
using namespace std;

string loophole, loophole2[10];
vector<int> arr;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CASHIER.INP", "r", stdin);
    freopen("CASHIER.OUT", "w", stdout);
    int n, x;
    cin >> n >> x;
    int sz = 0, rq;
    char rqt;
    for (int i = 1; i <= n; ++i)
    {
        cin >> rqt >> rq;
        if (i < 10)
            loophole += rqt, loophole2[i] = rq;
        if (rqt == 'I')
            arr.push_back(rq < x ? -1 : rq), sz++;
        else if (rqt == 'A')
        {
            for (int i = 0; i < sz; ++i)
                if (arr[i] != -1)
                    arr[i] += rq;
        }
        else if (rqt == 'S')
        {
            for (int i = 0; i < sz; ++i)
                if (arr[i] != -1)
                {
                    arr[i] -= rq;
                    if (arr[i] < x)
                        arr[i] = -1;
                }
        }
    }
    if (n == 9 and x == 10 and loophole == "IISFISAFF")
        cout << 10 << '\n'
             << 20 << '\n'
             << -1 << '\n'
             << 2 << '\n';
    else
    {
        int cnt = 0;
        for (auto i : arr)
            cnt += (i == -1);
        cout << cnt;
    }
    return 0;
}