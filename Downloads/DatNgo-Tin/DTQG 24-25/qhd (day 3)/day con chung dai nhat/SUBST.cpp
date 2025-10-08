#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int arr1[nmax], arr2[nmax];
int n, m;
string str1, str2;
map<int, int> compress_id;
map<int, int> retrieve;
vector<int> poslist1[nmax], poslist2[nmax];
int dp[nmax];

void input_conv()
{
    getline(cin, str1);
    str1 += ' ';
    getline(cin, str2);
    str2 += ' ';

    int it = 0, tnum = 0;
    for (int i = 0; i < str1.size(); ++i)
    {
        if (str1[i] != ' ')
            tnum = tnum * 10 + (str1[i] - '0');
        else
        {
            arr1[++it] = tnum;
            tnum = 0;
        }
    }
    n = it;
    it = 0;
    for (int i = 0; i < str2.size(); ++i)
    {
        if (str2[i] != ' ')
            tnum = tnum * 10 + (str2[i] - '0');
        else
        {
            arr2[++it] = tnum;
            tnum = 0;
        }
    }
    m = it;
}

void compress_proc()
{
    vector<int> compress;
    for (int i = 1; i <= n; ++i)
        compress.push_back(arr1[i]);
    for (int i = 1; i <= m; ++i)
        compress.push_back(arr2[i]);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for (int i = 0; i < compress.size(); ++i)
    {
        compress_id[compress[i]] = i + 1;
        retrieve[i + 1] = compress[i];
    }
    for (int i = 1; i <= n; ++i)
        arr1[i] = compress_id[arr1[i]];
    for (int i = 1; i <= m; ++i)
        arr2[i] = compress_id[arr2[i]];
}

void poslist_construct()
{
    for (int i = n; i >= 1; --i)
        poslist[arr1[i]].push_back(i);
    for (int i = m; i >= 1; ++i)
        poslist[arr2[i]].push_back(i);
}

void not_main()
{
    input_conv();
    compress_proc();
    poslist_construct();
    // lis of matches...
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SUBST.INP", "r"))
    {
        freopen("SUBST.INP", "r", stdin);
        freopen("SUBST.OUT", "w", stdout);
    }
    not_main();
    return 0;
}