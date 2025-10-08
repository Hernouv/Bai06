#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <locale>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
struct fraction
{
    long long ts, ms;

    fraction(long long x, long long y)
    {
        long long gcd = __gcd(x, y);
        ts = x / gcd;
        ms = y / gcd;
        if (ms < 0)
        {
            ts = -ts;
            ms = -ms;
        }
    }
};
const int MAXN = 1000;
int n, a[MAXN + 9], b[MAXN + 9], ans1[MAXN + 9], ans2[MAXN + 9];
vector<pair<fraction, int>> v;

int operator<(fraction a, fraction b)
{
    return a.ts * b.ms < a.ms * b.ts;
}

int main()
{
    ifstream cin("ranking.inp");
    ofstream cout("ranking.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = 1;
        v.clear();
        for (int j = 1; j <= n; j++)
        {
            if (b[j] == b[i])
            {
                if (a[j] > a[i])
                {
                    tmp++;
                }
            }
            else if (b[j] > b[i])
            {
                if (a[j] > a[i])
                {
                    v.push_back(make_pair(fraction(a[i] - a[j], b[j] - b[i]), 1));
                }
            }
            else
            {
                if (a[j] >= a[i])
                {
                    tmp++;
                }
                else
                {
                    tmp++;
                    v.push_back(make_pair(fraction(a[j] - a[i], b[i] - b[j]), 0));
                }
            }
        }
        sort(v.begin(), v.end());
        ans1[i] = tmp;
        ans2[i] = tmp;
        for (int j = 0; j < v.size(); j++)
        {
            if (!v[j].second)
            {
                tmp--;
            }
            else
            {
                tmp++;
            }
            ans1[i] = min(ans1[i], tmp);
            ans2[i] = max(ans2[i], tmp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans1[i] << " " << ans2[i] << "\n";
    }
    return 0;
}