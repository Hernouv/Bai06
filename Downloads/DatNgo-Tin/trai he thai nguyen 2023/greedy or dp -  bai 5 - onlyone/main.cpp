#include <bits/stdc++.h>
using namespace std;

double inv[1000001];
double prob[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> prob[i], prob[i] /= 1000000;
    for (int i = 1; i <= n; ++i) inv[i] = prob[i] / (1 - prob[i]);

}
