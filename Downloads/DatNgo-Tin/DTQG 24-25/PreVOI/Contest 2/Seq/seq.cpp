#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 3e5 + 5;

int N, K;
int A[nmax];
unordered_map<int, vector<int>> pos_map;

void not_main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        pos_map[A[i]].push_back(i);
    }
    int max_len = 0;

    for (pair<int, vector<int>> entry : pos_map)
    {
        vector<int> pos = entry.se;
        int M = pos.size();
        vector<int> gaps(M - 1);
        for (int i = 0; i < M - 1; ++i)
            gaps[i] = pos[i + 1] - pos[i] - 1;

        int l = 0;
        ll curr_gap = 0;
        for (int r = 0; r < M; ++r)
        {
            if (r > 0)
                curr_gap += gaps[r - 1];

            while (curr_gap > K)
            {
                curr_gap -= gaps[l];
                ++l;
            }
            int total_len = pos[r] - pos[l] + 1 + (K - curr_gap);
            minimize(total_len, N);
            maximize(max_len, total_len);
        }
    }

    cout << max_len << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("seq.inp", "r"))
    {
        freopen("seq.inp", "r", stdin);
        freopen("seq.out", "w", stdout);
    }
    not_main();
    return 0;
}
