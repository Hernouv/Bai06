#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

#define whole(_name) _name.begin(), _name.end()

const int nmax = 1e6 + 5;

vector<int> procX, procY;
char inp[nmax];
int dist[nmax];
int n;
char X, Y;
int res = 0;

int id(int num)
{
    num %= n;
    return (num ? num : n);
}

void not_main()
{
    cin >> n;
    char t_ch;
    for (int i = 1; i <= n; ++i)
        cin >> inp[i];
    cin >> X >> Y;
    if (X == Y)
    {
        cout << 0;
        return;
    }

    memset(dist, 0x3f, sizeof dist);
    for (int it = 1; it <= n; ++it)
    {
        if (inp[it] == X)
            procX.push_back(it);
        else if (inp[it] == Y)
            procY.push_back(it);
    }
    if (procX.back() > procY.back())
        procY.push_back(procY[0] + n);
    else
        procX.push_back(procY[0] + n);

    int szX = procX.size(), szY = procY.size();
    int it = 0;
    for (int p : procX)
    {
        while (it < szY and procY[it] < p)
            ++it;
        if (it == szY)
            break;
        minimize(dist[id(p)], procY[it] - p);
    }
    it = 0;
    for (int p : procY)
    {
        while (it < szX and procX[it] < p)
            ++it;
        if (it == szX)
            break;
        minimize(dist[id(procX[it])], procX[it] - p);
    }

    for (int p : procX)
        res = max(res, dist[id(p)]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("HAMSTER.INP", "r"))
    {
        freopen("HAMSTER.INP", "r", stdin);
        freopen("HAMSTER.OUT", "w", stdout);
    }
    not_main();
    return 0;
}