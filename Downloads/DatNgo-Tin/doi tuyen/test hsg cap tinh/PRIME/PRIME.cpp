#include <bits/stdc++.h>
using namespace std;

bool erastos[10000001];
int arr[100001];

void sieve(int vmax)
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= vmax; ++i)
        if (erastos[i])
            for (int j = i * i; j <= vmax; j += i)
                erastos[j] = false;
}

void proc(int num)
{
    string scan = to_string(num);
    map<int, bool> visited;
    for (int i = 0, sz = scan.size(); i < sz; ++i)
    {
        int check = scan[i] - '0';
        if (erastos[check])
            if (!visited[check])
            {
                cout << ' ' << check;
                visited[check] = true;
            }
    }
    if (visited.empty())
        cout << ' ' << 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);
    int t, vmax = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> arr[i];
        vmax = max(vmax, arr[i]);
    }
    sieve(vmax);
    for (int i = 1; i <= t; ++i)
    {
        if (erastos[arr[i]])
            cout << "YES";
        else
            cout << "NO";
        proc(arr[i]);
        cout << '\n';
    }
    return 0;
}