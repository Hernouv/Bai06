#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
const int N = 1e6 + 7;

struct dat
{
    int mx, idmx;
    vector<int> data, f;

    dat() = default;
    dat(const vector<int> &data) : data(data)
    {
        mx = idmx = 0;
        int d = 0;
        f.resize(data.size());
        for (int i = 0; i < data.size(); ++i)
        {
            if (maximize(mx, data[i]))
            {
                idmx = i;
                ++d;
            }
            f[i] = d;
        }
        for (int i = 0; i < data.size(); ++i)
        {
            f[i] = d - f[i];
        }
    }

    bool operator<(const dat &other)
    {
        if (mx != other.mx)
            return mx < other.mx;
        return idmx > other.idmx;
    }
};

struct BIT
{
    int bit[N];

    void update(int x, int val)
    {
        for (int i = x + 1; i < N; i += -i & i)
            maximize(bit[i], val);
    }

    int get(int x)
    {
        int ans = 0;
        for (int i = x + 1; i > 0; i -= -i & i)
            maximize(ans, bit[i]);
        return ans;
    }
} bit;

int n;
vector<dat> a;
vector<int> b;

void not_main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int &x : tmp)
            cin >> x;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (auto i : a)
    {
        int ans = 0;
        for (int j = 0; j < i.data.size(); ++j)
        {
            maximize(ans, bit.get(i.data[j] - 1) + i.f[j] + 1);
        }
        bit.update(i.mx, ans);
    }
    cout << bit.get(N - 3);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}