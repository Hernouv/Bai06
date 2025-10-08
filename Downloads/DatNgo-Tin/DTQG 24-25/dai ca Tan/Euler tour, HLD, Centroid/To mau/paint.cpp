#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int nmax = 100011;
const int inf = 1LL << 30;
const int MAXM = 200011;

const int SIZE = 600;

int n, m, ecnt, ans;
int First[nmax], to[MAXM], nxt[MAXM];
int deep[nmax], id[nmax];
int dui[nmax], head, tail, dis[nmax], ans_dis[nmax];
int D[nmax * 3], belong[nmax * 3];
int ST[nmax * 3][20], mi[20];
int Stack[SIZE + 12], top;

int getint()
{
    int w = 0, q = 0;
    char c = getchar();
    while ((c < '0' or c > '9') and c != '-')
        c = getchar();
    if (c == '-')
        q = 1, c = getchar();
    while (c >= '0' and c <= '9')
        w = w * 10 + c - '0', c = getchar();
    return q ? -w : w;
}

void dfs(int x, int fa)
{
    D[++ecnt] = x;
    id[x] = ecnt;
    for (int i = First[x]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        deep[v] = deep[x] + 1;
        dfs(v, x);
        D[++ecnt] = x;
    }
}

void build()
{
    belong[1] = 0;
    for (int i = 2; i <= ecnt; i++)
        belong[i] = belong[i / 2] + 1;
    mi[0] = 1;
    for (int i = 1; i <= 19; i++)
        mi[i] = mi[i - 1] * 2;
    for (int i = 1; i <= ecnt; i++)
        ST[i][0] = D[i];
    for (int j = 1; j <= 19; j++)
        for (int i = 1; i + mi[j - 1] - 1 <= ecnt; i++)
        {
            if (deep[ST[i + mi[j - 1]][j - 1]] > deep[ST[i][j - 1]])
                ST[i][j] = ST[i][j - 1];
            else
                ST[i][j] = ST[i + mi[j - 1]][j - 1];
        }
}

int lca(int x, int y)
{
    int f1 = id[x], f2 = id[y];
    if (f1 > f2)
        swap(f1, f2);
    int ll = f2 - f1 + 1, lr = belong[ll];
    if (deep[ST[f1][lr]] > deep[ST[f2 - (1 << lr) + 1][lr]])
        return ST[f2 - (1 << lr)][lr];
    else
        return ST[f1][lr];
}

void work()
{
    n = getint();
    m = getint();
    int x, y;
    for (int i = 2; i <= n; i++)
    {
        x = getint();
        y = getint();
        nxt[++ecnt] = First[x];
        First[x] = ecnt;
        to[ecnt] = y;
        nxt[++ecnt] = First[y];
        First[y] = ecnt;
        to[ecnt] = x;
    }
    ecnt = 0;
    dfs(1, 0);
    build();
    for (int i = 1; i <= n; i++)
        ans_dis[i] = deep[i];
    int ljh, u;
    while (m--)
    {
        ljh = getint();
        if (ljh == 2)
        {
            x = getint();
            for (int i = 1; i <= top; i++)
                ans_dis[x] = min(ans_dis[x], deep[x] + deep[Stack[i]] - deep[lca(x, Stack[i])] * 2);
            printf("%d\n", ans_dis[x]);
        }
        else
        {
            x = getint();
            if (x == 0)
                continue;
            Stack[++top] = x;
            if (top >= SIZE)
            {
                head = 0;
                tail = 0;
                for (int i = 1; i <= n; i++)
                    dis[i] = inf;
                for (int i = 1; i <= top; i++)
                    dui[++tail] = Stack[i], dis[Stack[i]] = 0;
                top = 0;
                while (head < tail)
                {
                    head++;
                    u = dui[head];
                    ans_dis[u] = min(ans_dis[u], dis[u]);
                    for (int i = First[u]; i; i = nxt[i])
                    {
                        int v = to[i];
                        if (dis[v] == inf)
                        {
                            dis[v] = dis[u] + 1;
                            dui[++tail] = v;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    work();
    return 0;
}