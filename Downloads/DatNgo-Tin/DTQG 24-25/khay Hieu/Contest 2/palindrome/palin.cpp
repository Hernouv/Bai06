#include <bits/stdc++.h>
using namespace std;

// Manacher’s Algorithm
pair<vector<int>, vector<int>> manacher(const string &s)
{
    int n = (int)s.size();
    vector<int> d1(n, 0), d2(n, 0);
    {
        int l = 0, r = -1;
        for (int i = 0; i < n; i++)
        {
            int k = 1;
            if (i <= r)
                k = min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                k++;
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
    }
    {
        int l = 0, r = -1;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            if (i <= r)
                k = min(d2[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
                k++;
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }
    }
    return {d1, d2};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    string S;
    cin >> S;

    auto [d1, d2] = manacher(S);

    // f[i]: difference array to count how many palindromes end at position i (1-based).
    vector<int> f(n + 2, 0);

    // Odd-length palindromes:
    // For center i (0-based), lengths = 1,3,...,(2*d1[i]-1)
    // Palindes end at positions: i+1, i+2, ..., i + d1[i]
    // Difference update:
    for (int i = 0; i < n; i++)
    {
        if (d1[i] > 0)
        {
            int startPos = i + 1;   // ends start at i+1
            int endPos = i + d1[i]; // ends at i+d1[i]
            if (startPos <= n)
                f[startPos] += 1;
            if (endPos + 1 <= n)
                f[endPos + 1] -= 1;
        }
    }

    // Even-length palindromes:
    // lengths: 2,4,...,(2*d2[i])
    // Palindes end at: i+1, i+2, ..., i + d2[i]
    for (int i = 0; i < n; i++)
    {
        if (d2[i] > 0)
        {
            int startPos = i + 1;   // ends start at i+1
            int endPos = i + d2[i]; // ends at i+d2[i]
            if (startPos <= n)
                f[startPos] += 1;
            if (endPos + 1 <= n)
                f[endPos + 1] -= 1;
        }
    }

    // Prefix sum f to get how many palindes end exactly at position i
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
    }

    // Now f[i] = how many palindes end at i
    // Create a prefix sum F[i] = total palindes in [1..i]
    vector<long long> F(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        F[i] = F[i - 1] + f[i];
    }

    // Query [l,r]: number of palindes fully in [l,r] = F[r]-F[l-1]
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (F[r] - F[l - 1]) << "\n";
    }

    return 0;
}
