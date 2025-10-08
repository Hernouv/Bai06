#include <bits/stdc++.h>

using namespace std;

const int cnst = 1e5;

int cnt = 0;               
vector<pair <int, int>> swaplist;   
int a[cnst + 1];                  
bool eratosthenes[cnst + 1];             
int pos[cnst + 1];

void sieve() 
{
    eratosthenes[0] = eratosthenes[1] = true;
    for (int i = 4; i <= cnst; i += 2)
        eratosthenes[i] = true;

    for (int i = 3; i <= floor(sqrt(cnst)); ++i)
        if (!eratosthenes[i]) 
            for (int j = i * i; j <= cnst; j += i) 
                eratosthenes[j] = true;
}

void permsort(int initialPos, int targetPos) 
{ 
    int m = initialPos - targetPos + 1;

    if (!eratosthenes[m]) 
    {
        swaplist.push_back({ targetPos,initialPos });
        swap(a[initialPos], a[targetPos]);
        swap(pos[a[initialPos]], pos[a[targetPos]]);
    }
    else 
    {
        while (eratosthenes[m]) m--;
        swap(a[initialPos], a[initialPos - m + 1]);
        swap(pos[a[initialPos]], pos[a[initialPos - m + 1]]);
        swaplist.push_back({ initialPos - m + 1, initialPos });
        permsort(initialPos - m + 1, targetPos);
    }
}

int main() 
{
    cin.tie(0) -> sync_with_stdio(false) ;
    freopen("permsort.inp", "r", stdin);
    freopen("permsort.out", "w", stdout);
    sieve();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
        if (a[i] != i) permsort(pos[i], i);

    cout << swaplist.size() << endl;
    for (auto x : swaplist)
        cout << x.first << ' ' << x.second << endl;
    return 0;
}