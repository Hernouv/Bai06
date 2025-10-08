#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll combine(deque<int>& a, deque<int>& b, int k) {
    if (a.size() < b.size()) swap(a, b);
    int as = a.size();
    int bs = b.size();

    // Count paths of length k
    ll res = 0;
    for (int i = max(0, (k - bs) + 1); i < min(k + 1, as); ++i) {
        res += a[i] * b[k-i];
    }

    // Combine a and b
    for (int i = 0; i < bs; ++i) a[i] += b[i];
    return res;
}

pair<ll, deque<int>> solve(int i, int k, int p, const vector<vector<int>>& g) {
    pair<ll, deque<int>> res = {(k == 0), {1}};
    for (int t : g[i]) {
        if (t == p) continue;
        auto sub = solve(t, k, i, g);
        sub.second.push_front(0);
        res.first += sub.first + combine(res.second, sub.second, k);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll res = solve(0, k, -1, g).first;
    cout << res << '\n';
}
