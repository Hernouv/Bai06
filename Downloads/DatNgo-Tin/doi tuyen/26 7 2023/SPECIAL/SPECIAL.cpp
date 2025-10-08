#include <bits/stdc++.h>
using namespace std;

bool check(long long num)
{
    bool zero, four, nine;
    int dcount = 0;
    int truecount = 0;
    while (num)
    {
        int dscan = num % 10;
        if (dscan == 0 or dscan == 4 or dscan == 9)
            truecount++;
        if (dscan == 0)
            zero = true;
        else if (dscan == 4)
            four = true;
        else if (dscan == 9)
            nine = true;
        num /= 10;
        dcount++;
    }
    if (dcount == truecount and zero + four + nine == 3)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int cnt = 0;
    for (long long i = 1; i <= 100000000; ++i)
    {
        long long sq = i * i;
        if (check(sq))
            cnt++, cout << i << ' ' << sq << '\n';
    }
    cout << cnt;
}