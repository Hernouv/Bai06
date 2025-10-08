#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> fibo(100, 0);
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= 100; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    int C = 0;
    while (C + 1 <= 100)
    {
        if (fibo[C + 1] >= N)
        {
            break;
        }
        C++;
    }
    cout << C;
}