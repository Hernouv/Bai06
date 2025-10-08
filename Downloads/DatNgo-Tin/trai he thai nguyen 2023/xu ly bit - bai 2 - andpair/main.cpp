#include <bits/stdc++.h>
using namespace std;

vector<int> a1, a2;
int res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        a1.push_back(temp);
    }
    sort(a1.begin(),a1.end(), greater<int>());
    for (int i = 30; i >= 0; --i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if ((a1[j] >> i) & 1) cnt++, a2.push_back(a1[j]);
        if (cnt > 1)
        {
            res += (1 << i);
            a1 = a2;
            n = a1.size();
        }
        a2 = {};
    }
    cout << res;
    return 0;
}
