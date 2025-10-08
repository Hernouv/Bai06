#include <bits/stdc++.h>
using namespace std;

int count(int n, int k) 
{
    if (n == 0 && k == 0) return 1;
    if (n <= 0 || k <= 0) return 0;
    return count(n - 1, k - n) + count(n - 1, k);
}


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int n, k;
        cin >> n >> k;
           cout << count(n, k) << '\n';
    }
    return 0;
}