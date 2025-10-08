#include <bits/stdc++.h>
using namespace std;

string org, after;
vector<int> ans;
int n;

void proc(string &org, int pos)
{
    int next = (pos + 1) % n;
    if (org[next] == org[pos])
    {
        if (org[next] == '1')
            org[next] = '0';
        else
            org[next] = '1';
        org[pos] = org[next];
        ans.push_back(pos);
        return;
    }
    proc(org, next);
    if (org[next] == '1')
        org[next] = '0';
    else
        org[next] = '1';
    org[pos] = org[next];
    ans.push_back(pos);
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> org >> after;
    n = org.size();

    while (true)
    {
        bool check = true;
        for (int i = 0; i < n; ++i)
        {
            if (org[i] != after[i])
            {
                proc(org, i);
                check = false;
                break;
            }
        }
        if (check)
            break;
    }

    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << '\n';

    return 0;
}