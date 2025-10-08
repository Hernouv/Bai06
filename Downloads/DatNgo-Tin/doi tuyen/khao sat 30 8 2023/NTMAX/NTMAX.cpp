#include <bits/stdc++.h>
using namespace std;

string inp;
int digit_cnt = 0;
int prime_max = 0, num_max = 0;
bool erastos[5000010];
vector<int> num_arr;

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= num_max; ++i)
        if (erastos[i])
            for (int j = i * i; j <= num_max; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("NTMAX.INP", "r", stdin);
    freopen("NTMAX.OUT", "w", stdout);
    cin >> inp;
    int sz = inp.size();
    inp = ' ' + inp;
    inp += 'a';
    int i = 1;
    while (i <= sz)
    {
        if (inp[i] - '0' < 10)
        {
            int num = 0;
            while (inp[i] - '0' < 10)
            {
                digit_cnt++;
                num *= 10;
                num += (inp[i] - '0');
                i++;
            }
            num_arr.push_back(num);
            num_max = max(num_max, num);
        }
        i++;
    }
    sieve();
    int res = 0;
    for (auto x : num_arr)
        if (erastos[x])
            res = max(res, x);
    cout << digit_cnt << '\n'
         << res;
    return 0;
}