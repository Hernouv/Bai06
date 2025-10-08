#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(_name) _name.begin(), _name.end()

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    ll sum_c = 0;
    for (auto& x : c)
    {
        cin >> x;
        sum_c += x;
    }

    vector<int> r(m);
    ll sum_r = 0;
    for (auto& x : r)
    {
        cin >> x;
        sum_r += x;
    }

    if (sum_c != sum_r)
    {
        cout << "No";
        return 0;
    }

    bool valid = true;
    for (auto x : c)
    {
        if (x < 0 or x > m)
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {
        for (auto x : r)
        {
            if (x < 0 or x > n)
            {
                valid = false;
                break;
            }
        }
    }
    if (!valid)
    {
        cout << "No";
        return 0;
    }

    vector<vector<int>> mat(n, vector<int>(m, 0));

    vector<int> cols(m);
    for (int j = 0; j < m; j++)
        cols[j] = j;

    for (int i = 0; i < n; i++)
    {
        sort(whole(cols), [&](const int a, const int b) -> bool
            {
                if (r[a] != r[b])
                    return r[a] > r[b];
                return a < b; });

        for (int k = 0; k < c[i]; k++)
        {
            if (k >= m or r[cols[k]] <= 0)
            {
                cout << "No";
                return 0;
            }
            mat[i][cols[k]] = 1;
            r[cols[k]]--;
        }
    }

    bool all_zero = true;
    for (auto x : r)
    {
        if (x != 0)
        {
            all_zero = false;
            break;
        }
    }

    if (all_zero)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j];
                if (j != m - 1)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        cout << "No";
    }
}
