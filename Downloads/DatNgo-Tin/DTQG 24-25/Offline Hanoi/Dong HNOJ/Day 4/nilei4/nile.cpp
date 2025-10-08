#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

int n;
int q;

struct UF
{
    int parent[nmax], sizee[nmax], minIndex[nmax];
    array<long long, 2> singledPat[nmax];
    long long singledBr[nmax];
    long long singled[nmax];
} u;

int W[nmax], A[nmax], B[nmax], E[nmax];
long long res[nmax];

struct Edge
{
    long long diff;
    int idx;
};
Edge edges[nmax];
pair<long long, int> bridging[nmax];
pair<long long, int> queriesVec[nmax];
int idx[nmax];
long long sortedW[nmax], d[nmax];

long long sumSingledGlobal = 0;

int findRoot(int x)
{
    if (u.parent[x] == x)
        return x;
    u.parent[x] = findRoot(u.parent[x]);
    return u.parent[x];
}

void updateSingled(int r)
{
    if (u.sizee[r] % 2 == 0)
    {
        u.singled[r] = 0;
    }
    else
    {
        long long val = min(u.singledPat[r][u.minIndex[r] % 2], u.singledBr[r]);
        if (val == LLONG_MAX)
            val = 0;
        u.singled[r] = val;
    }
}

void unionNodes(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if (a == b)
        return;

    sumSingledGlobal -= u.singled[a];
    sumSingledGlobal -= u.singled[b];

    if (u.sizee[a] < u.sizee[b])
        swap(a, b);
    u.parent[b] = a;

    int newSize = u.sizee[a] + u.sizee[b];
    int newMinIndex = min(u.minIndex[a], u.minIndex[b]);

    array<long long, 2> newSingledPat;
    newSingledPat[0] = min(u.singledPat[a][0], u.singledPat[b][0]);
    newSingledPat[1] = min(u.singledPat[a][1], u.singledPat[b][1]);

    long long newSingledBr = min(u.singledBr[a], u.singledBr[b]);

    u.sizee[a] = newSize;
    u.minIndex[a] = newMinIndex;
    u.singledPat[a] = newSingledPat;
    u.singledBr[a] = newSingledBr;

    updateSingled(a);

    sumSingledGlobal += u.singled[a];
}

void addBridging(int x, long long val)
{
    int r = findRoot(x);
    sumSingledGlobal -= u.singled[r];
    if (u.sizee[r] % 2 == 1)
    {
        u.singledBr[r] = min(u.singledBr[r], val);
        updateSingled(r);
    }
    else
    {
        u.singledBr[r] = min(u.singledBr[r], val);
    }
    sumSingledGlobal += u.singled[r];
}

void calculate_costs()
{
    for (int i = 0; i < n; ++i)
        idx[i] = i;
    sort(idx, idx + n, [&](int a, int b)
         { return W[a] < W[b]; });

    for (int i = 0; i < n; i++)
    {
        sortedW[i] = W[idx[i]];
        d[i] = (long long)A[idx[i]] - (long long)B[idx[i]];
    }

    long long sumB = 0;
    for (int i = 0; i < n; i++)
        sumB += B[idx[i]];

    for (int i = 0; i < n - 1; i++)
    {
        edges[i] = {sortedW[i + 1] - sortedW[i], i};
    }
    sort(edges, edges + n - 1, [&](const Edge &a, const Edge &b)
         { return a.diff < b.diff; });

    for (int i = 1; i < n - 1; i++)
    {
        long long val = sortedW[i + 1] - sortedW[i - 1];
        bridging[i - 1] = {val, i};
    }
    sort(bridging, bridging + n - 1, [&](auto &a, auto &b)
         { return a.first < b.first; });

    for (int i = 0; i < q; i++)
        queriesVec[i] = {(long long)E[i], i};
    sort(queriesVec, queriesVec + q, [&](auto &a, auto &b)
         { return a.first < b.first; });

    for (int i = 0; i < n; i++)
    {
        u.parent[i] = i;
        u.sizee[i] = 1;
        u.minIndex[i] = i;
        u.singledPat[i][0] = (i % 2 == 0) ? d[i] : LLONG_MAX;
        u.singledPat[i][1] = (i % 2 == 1) ? d[i] : LLONG_MAX;
        u.singledBr[i] = LLONG_MAX;
        u.singled[i] = d[i];
    }

    sumSingledGlobal = 0;
    for (int i = 0; i < n; i++)
        sumSingledGlobal += u.singled[i];

    int posE = 0;
    int posB = 0;

    for (int i = 0; i < q; i++)
    {
        long long D = queriesVec[i].first;
        int qidx = queriesVec[i].second;

        while (posE < n - 1 and edges[posE].diff <= D)
        {
            unionNodes(edges[posE].idx, edges[posE].idx + 1);
            posE++;
        }

        while (posB < n - 1 and bridging[posB].first <= D)
        {
            int x = bridging[posB].second;
            addBridging(x, d[x]);
            posB++;
        }

        long long costVal = sumB + sumSingledGlobal;
        res[qidx] = costVal;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str;
    cin >> str;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> W[i] >> A[i] >> B[i];

    cin >> q;
    for (int i = 0; i < q; ++i)
        cin >> E[i];

    cout << "4FBwMMwcdlgPodEtp0owUlxQgA5SuIlq\n";
    cout << "OK\n";
    calculate_costs();
    for (int i = 0; i < q; ++i)
        cout << res[i] << '\n';
}
