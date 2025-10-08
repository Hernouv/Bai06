#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;
vector<long long> divisor; // div2, t_div;

// long long gcd(long long x, long long y)
// {
//     while (x and y)
//     {
//         if (x > y)
//             x %= y;
//         else
//             y %= x;
//     }
//     return max(x, y);
// }

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> a >> b >> c >> d;
    long long mul = c / a;
    for (int i = 1; i * i <= mul; ++i)
        if (mul % i == 0)
        {
            divisor.push_back(i);
            divisor.push_back(mul / i);
        }
    int sz = divisor.size();
    if (divisor[sz - 1] == divisor[sz - 2])
        divisor.pop_back();

    sort(divisor.begin(), divisor.end());

    int iter = 0;
    for (auto x : divisor)
    {
        int check = a * x;
        if (check % b and d % check)
        {
            cout << check;
            break;
        }
        iter++;
    }
    if (iter == divisor.size())
        cout << -1;

    // cout << mul << ": ";
    // for (auto x : divisor)
    //     cout << x << ' ';
    // cout << '\n';

    // long long lcm_del = (a * b / gcd(a, b)) / a;
    // cout << lcm_del << '\n';
    // for (auto x : divisor)
    //     if (x % lcm_del != 0)
    //         div2.push_back(x);
    // divisor.clear();

    // cout << div2.size() << '\n';
    // cout << mul << ": ";
    // for (auto x : div2)
    //     cout << x << ' ';
    // cout << '\n';

    // if (d % a == 0)
    // {
    //     long long t_mul = d / a;
    //     long long common = gcd(t_mul, mul);
    //     for (int i = 1; i * i <= common; ++i)
    //         if (common % i)
    //         {
    //             t_div.push_back(common);
    //             t_div.push_back(common / i);
    //         }
    //     int sz = t_div.size();
    //     if (t_div[sz - 1] == t_div[sz - 2])
    //         t_div.pop_back();
    //     sort(t_div.begin(), t_div.end());
    //     int iter = 0;
    //     for (auto x : div2)
    //         if (x == t_div[iter])
    //         {
    //             divisor.push_back(x);
    //             iter++;
    //         }
    //     div2.clear();
    // }
    // else
    // {
    //     for (auto x : div2)
    //         divisor.push_back(x);
    //     div2.clear();
    // }

    // cout << mul << ": ";
    // for (auto x : divisor)
    //     cout << x << ' ';
    // cout << '\n';

    // if (divisor.empty())
    //     cout << -1 << '\n';
    // else
    //     cout << a * divisor[0] << '\n';

    // for (auto x : divisor)
    // {
    //     int check = a * x;
    //     if (check % b and d % check)
    //     {
    //         cout << check;
    //         break;
    //     }
    // }
    return 0;
}