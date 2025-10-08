#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;
int arr[nmax], pos[nmax], swaps[nmax]{0};
int ar2[nmax];
int n;

void reset()
{
    for (int i = 1; i <= n; ++i)
        pos[arr[i]] = i;
    for (int i = 1; i <= n; ++i)
        ar2[i] = arr[i];
}

void countL(vector<int> L, int k)
{
    int lim = k - 1;
    for (int i = 0; i < L.size(); ++i)
    {
        swaps[k] += ((lim - i) - pos[L[i]]);
        if (pos[L[i]] < lim - i)
        {
            for (int j = pos[L[i]] + 1; j <= lim - i; ++j)
            {
                --pos[ar2[j]];
                ar2[j - 1] = ar2[j];
            }
            pos[L[i]] = lim - i;
            ar2[lim - i] = L[i];
        }
    }
}

void countR(vector<int> R, int k)
{
    int lim = k + 1;
    for (int i = 0; i < R.size(); ++i)
    {
        swaps[k] += (pos[R[i]] - (lim + i));
        if (pos[R[i]] > lim + i)
        {
            for (int j = pos[R[i]] - 1; j >= lim + i; --j)
            {
                ++pos[ar2[j]];
                ar2[j + 1] = ar2[j];
            }
            pos[R[i]] = lim + i;
            ar2[lim + i] = R[i];
        }
    }
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    for (int k = 1; k <= n; ++k)
    {
        reset();
        if (pos[n] < k)
        {
            swaps[k] += (k - pos[n]);
            for (int i = pos[n] + 1; i <= k; ++i)
            {
                --pos[ar2[i]];
                ar2[i - 1] = ar2[i];
            }
        }
        else if (pos[n] > k)
        {
            swaps[k] += (pos[n] - k);
            for (int i = pos[n] - 1; i >= k; --i)
            {
                ++pos[ar2[i]];
                ar2[i + 1] = ar2[i];
            }
        }
        pos[n] = k;
        ar2[k] = n;

        vector<int> L, R;
        for (int i = 1; i <= n; ++i)
        {
            if (pos[arr[i]] < k)
                L.push_back(arr[i]);
            else if (pos[arr[i]] > k)
                R.push_back(arr[i]);
        }
        sort(L.begin(), L.end(), greater<int>());
        sort(R.begin(), R.end(), greater<int>());
        countL(L, k);
        countR(R, k);
    }

    for (int i = 1; i <= n; ++i)
        cout << swaps[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SWAP.INP", "r"))
    {
        freopen("SWAP.INP", "r", stdin);
        freopen("SWAP.OUT", "w", stdout);
    }
    not_main();
    return 0;
}