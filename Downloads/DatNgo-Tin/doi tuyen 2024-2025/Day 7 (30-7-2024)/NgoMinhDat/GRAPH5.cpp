#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int iatv[10001], lvvi[10001], nv, ne, ccno = 0, ia = 0;
stack<int> vocc;
bool apocc[10001];
vector<int> scc[10001];

void tarjan(int index)
{
    ia++;
    iatv[index] = lvvi[index] = ia;
    vocc.push(ia);

    for (auto v : graph[index])
    {
        if (!apocc[v])
        {
            if (iatv[v])
                lvvi[index] = min(lvvi[index], iatv[v]);
            else
            {
                tarjan(v);
                lvvi[index] = min(lvvi[index], lvvi[v]);
            }
        }
    }

    if (iatv[index] == lvvi[index])
    {
        ccno++;
        int t;
        do
        {
            t = vocc.top();
            apocc[t] = true;
            scc[ccno].push_back(t);
            vocc.pop();
        } while (t != index);
        sort(scc[ccno].begin(), scc[ccno].end());
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(apocc, false, sizeof(apocc));
    cin >> nv >> ne;
    for (int i = 1; i <= ne; ++i)
    {
        int esvi, eevi;
        cin >> esvi >> eevi;
        graph[esvi].push_back(eevi);
    }

    for (int i = 1; i <= nv; ++i)
        if (!apocc[i])
            tarjan(i);

    cout << ccno << '\n';
    for (int i = 1; i <= ccno; ++i)
    {
        for (int x : scc[i])
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}