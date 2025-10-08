#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int b[30010];

int main()
{
    int n;
    cin >> n;
    int n_inp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> n_inp;
        a.push_back(n_inp);
    }
    memset(b, 0x3f, sizeof(b));
    int result = 0;
    for (int x : a)
    {
        int k = lower_bound(b + 1, b + n + 1, x) - b;
        b[k] = x;
        result = max(result, k);
    }
    cout << result;
}
// int result = 0;
// for (int x : a)
// {
//     int k = lower_bound(b.begin(), b.end(), x) - b.begin();
//     b[k] = x;
//     result = max(result, k);
//     cout << result + 1;
// }
// if using lower_bound with vector
