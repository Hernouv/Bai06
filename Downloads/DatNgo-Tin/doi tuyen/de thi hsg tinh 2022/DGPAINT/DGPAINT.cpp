#include <bits/stdc++.h>
using namespace std;

int T, N, a, b, p, q;

int gcd(int a, int b)
{
    while (a and b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return max(a, b);
}

void proc()
{
    cin >> N >> a >> b >> p >> q;

    int limHi_a = (N / a) * a;
    int limHi_b = (N / b) * b;
    int ab = a * b / gcd(a, b);
    int limHi_ab = (N / ab) * ab;

    int earn_a = (limHi_a - a) / a + 1;
    int earn_b = (limHi_b - b) / b + 1;
    int earn_ab = (limHi_ab - ab) / ab + 1;

    cout << earn_a * p + earn_b * q - earn_ab * min(p, q) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("DGPAINT.INP", "r", stdin);
    // freopen("DGPAINT.OUT", "w", stdout);
    cin >> T;
    while (T--)
        proc();
    return 0;
}