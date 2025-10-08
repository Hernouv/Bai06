#include <bits/stdc++.h>
using namespace std;

namespace personA
{
    const int base1 = 101;
    const int base2 = 101;

    pair<int, int> A2B(vector<int> _A)
    {
        int a = 0, b = 0;
        for (auto x : _A)
        {
            a = (a + x) % base1;
            b = (b + x * x) % base2;
        }
        return {a + 1, b + 1};
    }
}

namespace personB
{
    const int base1 = 101;
    const int base2 = 101;

    pair<int, int> Btell(vector<int> _B, pair<int, int> _P)
    {
        int a = _P.first - 1;
        int b = _P.second - 1;

        int s1 = 0, s2 = 0;

        for (int i = 1; i <= 100; i++)
        {
            s1 = (s1 + i) % base1;
            s2 = (s2 + i * i) % base2;
        }

        for (int x : _B)
        {
            a = (a + x) % base1;
            b = (b + x * x) % base2;
        }

        int cnt = 0, li, lj;
        for (int i = 1; i < 100; i++)
        {
            for (int j = i + 1; j <= 100; j++)
            {
                if (((a + i + j) % base1 == s1) && ((b + i * i + j * j) % base2 == s2))
                {
                    cnt++;
                    li = i;
                    lj = j;
                }
            }
        }
        assert(cnt == 1);
        return {li, lj};
    }
}
