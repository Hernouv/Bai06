#include <bits/stdc++.h>

using namespace std;

#define task "GLASS"
#define endl ('\n')
#define MASK(i) (1LL << (i))                                 // mask cuối cùng cộng 1 //11111 + 1 = 100000
#define BIT(x, i) (((x) >> (i)) & 1)                         // bit thứ i của mask x
#define COMPLEMENT(x, num_bit) ((MASK((num_bit)) - 1) ^ (x)) // phần bù của mask x
#define MAX 22
#define MOD

template <class T>
inline bool maximize(T &r, const T &v)
{
    return (r < v ? r = v, 1 : 0);
}
template <class T>
inline bool minimize(T &r, const T &v)
{
    return (r > v ? r = v, 1 : 0);
}

int numCup, maximumCup;
int cost[MAX][MAX];
int minCost[MASK(MAX)];

string bitDisplay(int inp)
{
    string ret = "";
    do
    {
        ret = char(inp % 2 + '0') + ret;
        inp /= 2;
    } while (inp);
    return ret;
}

void algorithm()
{
    cin >> numCup >> maximumCup;
    for (int i = 0; i < numCup; ++i)
    {
        for (int j = 0; j < numCup; ++j)
        {
            cin >> cost[i][j];
        }
    }
    memset(minCost, 0x3f, sizeof minCost);
    minCost[MASK(numCup) - 1] = 0;
    // gọi minCost[mask] là chi phí nhỏ nhất khi chọn uống các cốc tương ứng với mask
    // từ đó suy ra mask
    for (int mask = MASK(numCup) - 1; mask >= 1; --mask)
    {
        int comple = COMPLEMENT(mask, numCup);
        cout << bitDisplay(comple) << ":\n";
        for (int temp = comple; temp > 0; temp ^= temp & -temp)
        {
            cout << bitDisplay(temp) << ' ';
            int pos = __builtin_ctz(temp);
            cout << bitDisplay(MASK(pos)) << ' ';
            int preMask = (mask | MASK(pos));
            cout << "pM-" << bitDisplay(preMask) << '\n';
            for (int i = 0; i < numCup; ++i)
            {
                if (BIT(mask, i))
                    minimize(minCost[mask], minCost[preMask] + cost[pos][i]);
            }
        }
        cout << '\n';
    }
    int res = (int)1e9 + 7;
    for (int i = 1; i < MASK(numCup); ++i)
    {
        if (__builtin_popcount(i) <= maximumCup)
        {
            minimize(res, minCost[i]);
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    algorithm();
    return 0;
}