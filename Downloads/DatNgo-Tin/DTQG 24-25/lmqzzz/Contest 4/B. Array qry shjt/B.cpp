#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(__) __.begin(), __.end()

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &x : A)
        cin >> x;
    sort(whole(A));
    A.erase(unique(whole(A)), A.end());
    ll max_count = 0;
    int left = 0;
    int size = A.size();
    for (int right = 0; right < size; ++right)
    {
        while (left <= right and A[right] > A[left] + K - 1)
            left++;
        ll current_window_size = right - left + 1;
        if (current_window_size > max_count)
            max_count = current_window_size;
    }
    ll M = K - max_count;
    if (M < 0)
        M = 0;
    cout << M;
    return 0;
}
