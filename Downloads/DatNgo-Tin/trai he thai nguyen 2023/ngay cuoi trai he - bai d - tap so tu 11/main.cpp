#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i)
    {
        int num;
        cin >> num;
        int scan = 111111111;
        int checkn = 0;
        while (scan != 1)
        {
            if (scan <= num)
            {
                while (checkn <= num) checkn += scan;
                checkn -= scan;
                if (checkn == num)
                {
                    cout << "YES" << '\n';
                    break;
                }
                int t = scan / 10;
                while (num - checkn <= t) checkn -= scan;
            }
            scan /= 10;
        }
        if (scan == 1) cout << "NO" << '\n';
    }
    return 0;
}
