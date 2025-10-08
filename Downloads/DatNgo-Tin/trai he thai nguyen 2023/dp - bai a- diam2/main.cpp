#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int maxbranch[200001], branchdist[200001];
vector<int> descendants[200001];
string inp;
stack<int> scan = {1};

int ia = 1; //index assigner

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> inp;
    const int sz = inp.size();
    for (int i = 0; i < sz; ++i)
    {
        if (inp[i] == '(')
        {
            ++ia;
            descendants[scan.top()].push_back(ia);
            parent[ia] = scan.top();
            scan.push(ia);
        }
        else if (inp[i] == ')')
        {
            scan.pop();
        }
    }
    for (int i = 1; i <= ia; ++i)
    {
        if (!descendants[i].empty)
        {
            int p = parents[i];
            while(p and descendants[p].size < 2) maxbranch[p] =
        }
    }
}
