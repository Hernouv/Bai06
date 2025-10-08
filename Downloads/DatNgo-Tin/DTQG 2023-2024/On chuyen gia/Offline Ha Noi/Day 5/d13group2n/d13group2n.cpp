#include <bits/stdc++.h> //hi
using namespace std;

#define endl '\n'
#define int long long

int n;
int A[1000010];
int tA[1000010];
vector<int> dinhke[100010];

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        tA[i] = A[i];
    }
}

bool NT[10000010];
void sang(int x)
{
    memset(NT, true, sizeof(NT));
    NT[0] = NT[1] = false;
    for (int i = 2; i <= x; i++)
    {
        if (NT[i] == true)
        {
            for (int j = 2 * i; j <= x; j += i)
            {
                NT[j] = false;
            }
        }
    }
}

bool visited[100010];
int righ[100010];

bool match(int u)
{
    if (visited[u])
        return 0;
    visited[u] = 1;

    for (int v : dinhke[u])
    {
        if (righ[v] == 0 || match(righ[v]))
        {
            righ[v] = u;
            return 1;
        }
    }

    return 0;
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}
struct node_12
{
    vector<pair<int, int>> B[2];
    void set_up()
    {
        for (int i = 1; i <= n; i++)
        {
            int id = A[i] % 2;
            B[id].push_back({A[i], i});
        }
        sort(B[1].begin(), B[1].end(), cmp);
    }

    vector<pair<int, int>> res;
    void sol()
    {
        set_up();

        for (auto &[w, id] : B[1])
        {
            for (auto &[w1, id1] : B[0])
            {
                if (NT[w + w1] == true)
                {
                    // cout << w << ' ' << id << ' ' << w1 << ' ' << id1 << endl;
                    dinhke[id].push_back(id1);
                }
            }
        }

        int pos = -1;
        int cnt = 0;
        for (int i = 0; i < B[1].size(); i++)
        {
            int id = B[1][i].second, w = B[1][i].first;
            memset(visited, 0, sizeof(visited));
            if (match(id))
                cnt++;
            else if (w == 1)
            {
                pos = i;
                break;
            }
        }

        vector<pair<int, int>> res;
        for (int i = 1; i <= n; i++)
            if (righ[i] != 0)
                res.push_back({i, righ[i]});

        if (pos != -1)
        {
            for (int i = pos + 1; i < B[1].size(); i += 2)
            {
                int id = B[1][i].second, w = B[1][i].first;
                res.push_back({B[1][i - 1].second, B[1][i].second});
            }
        }

        cout << res.size() << endl;
        for (auto &[u, v] : res)
            cout << u << ' ' << v << endl;
    }
} sub12;

void sub13()
{
    if (n & 1)
        --n;
    cout << n / 2 << '\n';
    int i = n, j = n - 1;
    while (j and i)
    {
        if (NT[i + j])
        {
            int ti = i, tj = j;
            while (tj < ti)
            {
                cout << ti << ' ' << tj << endl;
                tj++;
                ti--;
            }
            i = j - 1;
            j--;
        }
        j--;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    in();
    sang(2000000);

    bool s13 = true;
    sort(tA + 1, tA + n + 1);
    for (int i = 2; i <= n; ++i)
        if (tA[i] != tA[i - 1] + 1)
        {
            s13 = false;
            break;
        }

    if (!s13)
        sub12.sol();
    else
        sub13();
    return 0;
}