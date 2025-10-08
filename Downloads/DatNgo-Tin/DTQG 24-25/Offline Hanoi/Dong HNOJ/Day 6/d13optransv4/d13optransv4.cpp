#include <bits/stdc++.h>
using namespace std;

vector<int> id[9];
bool grid[1100][1100];
bitset<1030> col[1100][2], row[1100][2];
int m, n, st = 1;
string s;
char trans[9];

void initialize()
{
    id[1] = {1, 2, 3, 4};
    id[2] = {4, 1, 2, 3};
    id[3] = {3, 4, 1, 2};
    id[4] = {2, 3, 4, 1};
    id[5] = {1, 4, 3, 2};
    id[6] = {2, 1, 4, 3};
    id[7] = {3, 2, 1, 4};
    id[8] = {4, 3, 2, 1};

    trans[5] = '1';
    trans[7] = '2';
    trans[8] = 'H';
    trans[6] = 'V';
    trans[2] = 'A';
    trans[3] = 'B';
    trans[4] = 'C';
}

int find_id(vector<int> vt)
{
    for (int i = 1; i <= 8; ++i)
    {
        if (id[i] == vt)
            return i;
    }
}

void not_main()
{
    initialize();
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    cin >> s;
    vector<int> ini = id[1];
    for (char ch : s)
    {
        if (ch == '1')
        {
            swap(ini[1], ini[3]);
            st = find_id(ini);
            continue;
        }
        if (ch == '2')
        {
            swap(ini[0], ini[2]);
            st = find_id(ini);
            continue;
        }
        if (ch == 'H')
        {
            swap(ini[0], ini[3]);
            swap(ini[1], ini[2]);
            st = find_id(ini);
            continue;
        }
        if (ch == 'V')
        {
            swap(ini[0], ini[1]);
            swap(ini[2], ini[3]);
            st = find_id(ini);
            continue;
        }
        if (ch == 'A' or ch == 'Z')
        {
            int incr = (st % 4 + 1) % 4;
            st = (st - 1) / 4 + (incr ? incr : 4);
            ini = id[st];
            continue;
        }
        if (ch == 'B' or ch == 'Y')
        {
            int incr = (st % 4 + 2) % 4;
            st = (st - 1) / 4 + (incr ? incr : 4);
            ini = id[st];
            continue;
        }
        if (ch == 'C' or ch == 'X')
        {
            int incr = (st % 4 + 3) % 4;
            st = (st - 1) / 4 + (incr ? incr : 4);
            ini = id[st];
            continue;
        }
    }

    if (st == 1)
    {
        cout << "[]";
        exit(0);
    }
    char trans_res = trans[st];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (grid[i][j])
            {
                row[i][0] |= (1 << (j - 1));
                col[j][0] |= (1 << (i - 1));
            }
        }
    for (int i = m; i > 0; --i)
        for (int j = n; j > 0; --j)
        {
            if (grid[i][j])
            {
                row[i][1] |= (1 << (n - j));
                col[j][1] |= (1 << (m - i));
            }
        }

    if (trans_res == '1')
    {
        if (m != n)
        {
            cout << "[1]";
            exit(0);
        }
        bool palin = true;
        for (int i = 1; i <= n; ++i)
            if (row[i][0] != col[i][0])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[1]";
        exit(0);
    }
    if (trans_res == '2')
    {
        if (m != n)
        {
            cout << "[2]";
            exit(0);
        }
        bool palin = true;
        for (int i = 1; i <= m; ++i)
            if (col[i][0] != row[m - i + 1][1])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[2]";
        exit(0);
    }
    if (trans_res == 'H')
    {
        bool palin = true;
        for (int i = 1; i <= n; ++i)
            if (col[i][0] != col[i][1])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[H]";
        exit(0);
    }
    if (trans_res == 'V')
    {
        bool palin = true;
        for (int i = 1; i <= m; ++i)
            if (row[i][0] != row[i][1])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[V]";
        exit(0);
    }
    if (trans_res == 'A')
    {
        if (m != n)
        {
            cout << "[A]";
            exit(0);
        }
        bool palin = true;
        for (int i = 1; i <= m; ++i)
            if (row[i][0] != col[m - i + 1][0])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[A]";
        exit(0);
    }
    if (trans_res == 'B')
    {
        bool palin = true;
        for (int i = 1; i <= m; ++i)
            if (row[i][0] != row[m - i + 1][1])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[B]";
        exit(0);
    }
    if (trans_res == 'C')
    {
        if (m != n)
        {
            cout << "[X]";
            exit(0);
        }
        bool palin = true;
        for (int i = 1; i <= m; ++i)
            if (row[i][0] != col[i][1])
            {
                palin = false;
                break;
            }
        if (palin)
            cout << "[]";
        else
            cout << "[C]";
        exit(0);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
