#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 18;
template <class T>
struct binary_indexed_tree
{
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0)
    {
    }
    void add(int i, T x)
    {
        i++;
        while (i <= N)
        {
            BIT[i] += x;
            i += i & (-i);
        }
    }
    T sum(int i)
    {
        T ans = 0;
        while (i > 0)
        {
            ans += BIT[i];
            i -= i & (-i);
        }
        return ans;
    }
};

void not_main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(N - 1), B(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<int> P(M), C(M);
    for (int i = 0; i < M; i++)
    {
        cin >> P[i] >> C[i];
        P[i]--;
    }
    vector<int> S(Q), T(Q);
    vector<int> X(Q);
    vector<ll> Y(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> S[i] >> T[i] >> X[i] >> Y[i];
        S[i]--;
        T[i]--;
    }
    vector<vector<int>> E(N);
    for (int i = 0; i < N - 1; i++)
    {
        E[A[i]].push_back(B[i]);
        E[B[i]].push_back(A[i]);
    }
    vector<int> p(N, -1);
    vector<vector<int>> c(N);
    vector<int> d(N, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : E[v])
        {
            if (w != p[v])
            {
                p[w] = v;
                c[v].push_back(w);
                d[w] = d[v] + 1;
                q.push(w);
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (B[i] == p[A[i]])
        {
            swap(A[i], B[i]);
        }
    }
    vector<vector<int>> pp(LOG, vector<int>(N, -1));
    pp[0] = p;
    for (int i = 0; i < LOG - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (pp[i][j] != -1)
            {
                pp[i + 1][j] = pp[i][pp[i][j]];
            }
        }
    }
    vector<int> L(Q);
    for (int i = 0; i < Q; i++)
    {
        int u = S[i], v = T[i];
        if (d[u] > d[v])
        {
            swap(u, v);
        }
        for (int j = 0; j < LOG; j++)
        {
            if (((d[v] - d[u]) >> j & 1) == 1)
            {
                v = pp[j][v];
            }
        }
        if (u == v)
        {
            L[i] = u;
        }
        else
        {
            for (int j = LOG - 1; j >= 0; j--)
            {
                if (pp[j][u] != pp[j][v])
                {
                    u = pp[j][u];
                    v = pp[j][v];
                }
            }
            L[i] = p[u];
        }
    }
    vector<int> in(N), out(N);
    int t = 0;
    auto dfs = [&](auto dfs, int v = 0) -> void
    {
        if (v != 0)
        {
            in[v] = t;
            t++;
        }
        for (int w : c[v])
        {
            dfs(dfs, w);
        }
        if (v != 0)
        {
            out[v] = t;
            t++;
        }
    };
    dfs(dfs);
    in[0] = -1;
    vector<pair<int, int>> D(M);
    for (int i = 0; i < M; i++)
    {
        D[i] = make_pair(C[i], P[i]);
    }
    sort(D.begin(), D.end());
    vector<int> tv(Q, -1), fv(Q, M + 1);
    vector<int> cnt(Q);
    while (true)
    {
        bool ok = true;
        vector<vector<int>> id(M + 1);
        for (int i = 0; i < Q; i++)
        {
            if (fv[i] - tv[i] > 1)
            {
                ok = false;
                id[(tv[i] + fv[i]) / 2].push_back(i);
            }
        }
        if (ok)
        {
            break;
        }
        binary_indexed_tree<int> BIT1(N * 2 - 2);
        binary_indexed_tree<ll> BIT2(N * 2 - 2);
        for (int i = 0; i < M; i++)
        {
            BIT1.add(in[B[P[i]]], 1);
            BIT1.add(out[B[P[i]]], -1);
        }
        for (int i = 0; i <= M; i++)
        {
            for (int j : id[i])
            {
                ll s = BIT2.sum(in[S[j]] + 1) + BIT2.sum(in[T[j]] + 1) - BIT2.sum(in[L[j]] + 1) * 2;
                if (s <= Y[j])
                {
                    cnt[j] = BIT1.sum(in[S[j]] + 1) + BIT1.sum(in[T[j]] + 1) - BIT1.sum(in[L[j]] + 1) * 2;
                    tv[j] = i;
                }
                else
                {
                    fv[j] = i;
                }
            }
            if (i < M)
            {
                int x = D[i].first;
                int e = D[i].second;
                BIT1.add(in[B[e]], -1);
                BIT1.add(out[B[e]], 1);
                BIT2.add(in[B[e]], x);
                BIT2.add(out[B[e]], -x);
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cout << max(X[i] - cnt[i], -1) << "\n";
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}