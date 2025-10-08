#include <bits/stdc++.h>
using namespace std;

// int countEven(int lo, int hi)
// {
//     return (hi / 2 - (lo - 1) / 2);
// }

// int sumRange(int lo, int hi)
// {
//     return hi * (hi + 1) / 2 - (lo - 1) * ((lo - 1) + 1) / 2;
// }

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("TRIANGLE.INP", "r", stdin);
    // freopen("TRIANGLE.OUT", "w", stdout);
    int n;
    while (cin >> n)
    {
        unsigned long long res = 0;
        int hi = n / 2;
        int lo = n / 3;
        // int cEven = countEven(lo, hi);
        // int cOdd = (hi - lo + 1) - cEven;
        // if (n % 3)
        //     lo++;

        // int lowestEven, lowestOdd;
        // lowestOdd = lo + 1, lowestEven = lo;
        // if (lo % 2)
        //     swap(lowestOdd, lowestEven);

        // // int accumSum = sumRange(lo, hi);
        // int sumEven = cEven * lowestEven + cEven * (cEven - 1) / 2;
        // int sumOdd = cOdd * lowestOdd + cOdd * (cOdd - 1) / 2;
        for (int i = lo; i <= hi; ++i)
        {
            int rem2_edgelength = n - i;
            res += (i - rem2_edgelength / 2 + not(rem2_edgelength % 2));
        }
        // res += sumEven + sumOdd - (cEven + cOdd) * n / 2 + (sumEven + sumOdd) / 2 + cOdd;
        cout << res << '\n';
    }
    return 0;
}