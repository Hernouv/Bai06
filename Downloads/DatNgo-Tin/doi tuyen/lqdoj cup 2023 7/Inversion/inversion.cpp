#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    int bn;
    vector<int> bA;

    BIT() { bn = 0; }
    BIT(int bn_)
    {
        bn = bn_;
        bA.resize(bn + 1);
        fill(bA.begin(), bA.end(), 0);
    }

    int prefix(int bposn)
    {
        if (bposn <= 0)
            return 0;
        if (bposn > bn)
            bposn = bn;

        int ret = 0;
        for (int i = bposn; i > 0; i -= ((i) & (-i)))
            ret += bA[i];
        return ret;
    }

    void update(int bposn, int bincr)
    {
        if (bposn <= 0)
            return;
        if (bposn > bn)
            return;

        for (int i = bposn; i <= bn; i += ((i) & (-i)))
            bA[i] += bincr;
    }

    int query(int bl, int br)
    {
        if (br <= 0 or bl > bn or bl > br)
            return 0;
        if (bl <= 0)
            bl = 1;
        if (br > bn)
            br = bn;
        return (prefix(br) - prefix(bl - 1));
    }
};

struct query_t
{
    int l, r, ix;
    query_t(int l_, int r_, int ix_)
    {
        l = l_;
        r = r_;
        ix = ix_;
    }
};

bool operator<(query_t q1, query_t q2)
{
    return (q1.r < q2.r);
}

const int max_n = 20010;
const int max_q = 20010;
int n, q, l, r;
int a[max_n];
int ta[max_n];
map<int, int> M;
int cnt;
vector<query_t> chunks[150];
int ans[max_q];
BIT bit;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("INVERSION.INP", "r"))
    {
        freopen("INVERSION.INP", "r", stdin);
        freopen("INVERSION.OUT", "w", stdout);
    }
    cin >> n;
    int root = (int)ceil(sqrt(double(n)));
    char t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[i] = int(t);
        ta[i] = a[i];
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> l >> r;
        l--;
        r--;
        chunks[l / root].push_back(query_t(l, r, i));
    }

    sort(ta, ta + n);
    cnt = int(unique(ta, ta + n) - ta);
    for (int i = 0; i < n; ++i)
        a[i] = 1 + int(lower_bound(ta, ta + cnt, a[i]) - ta);
    int sz = (n + root - 1) / root;
    n = cnt;
    for (int i = 0; i < sz; ++i)
    {
        int cl = root * i;
        int cr = cl - 1;
        int res = 0;
        bit = BIT(n);
        sort(chunks[i].begin(), chunks[i].end());
        for (int j = 0; j < chunks[i].size(); ++j)
        {
            l = chunks[i][j].l;
            r = chunks[i][j].r;
            int ix = chunks[i][j].ix;
            while (cr != r)
            {
                ++cr;
                res += bit.query(a[cr] + 1, n);
                bit.update(a[cr], 1);
            }
            if (l >= cl)
            {
                while (cl != l)
                {
                    res -= bit.prefix(a[cl] - 1);
                    bit.update(a[cl], -1);
                    ++cl;
                }
            }
            else
            {
                while (cl != l)
                {
                    --cl;
                    res += bit.prefix(a[cl] - 1);
                    bit.update(a[cl], 1);
                }
            }
            ans[ix] = res;
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}