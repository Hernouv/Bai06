#include <bits/stdc++.h> //hi
using namespace std;

#define endl '\n'
#define int long long

int n;
int A[200010];

void sol()
{
    int timee = 0;
    while (true)
    {
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (A[i] > 1)
            {
                flag = true;
                int j = i;
                while (j <= n)
                {
                    int step = A[j];
                    if (A[j] > 1)
                        A[j]--;
                    j += step;
                }
                break;
            }
        }
        if (flag == false)
            break;
        timee++;
    }
    cout << timee << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRAMPOLINE.inp", "r", stdin);
    freopen("TRAMPOLINE.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        sol();
    }
    return 0;
}