#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> sequence(n + 5);
    sequence[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> sequence[i];
    }

    int ptr = n + 1;

    vector<long long> results;

    while (q--)
    {
        char query;
        cin >> query;

        if (query == 'A')
        {
            int x;
            cin >> x;
            sequence.insert(sequence.begin() + ptr, x);
            ptr++;
        }
        else if (query == 'D')
        {
            if (ptr > 1)
            {
                sequence.erase(sequence.begin() + ptr - 1);
                ptr--;
            }
        }
        else if (query == 'L')
        {
            if (ptr > 1)
            {
                ptr--;
            }
        }
        else if (query == 'R')
        {
            if (ptr < sequence.size() - 1)
            {
                ptr++;
            }
        }
        else if (query == 'Q')
        {
            int l, r;
            cin >> l >> r;

            long long sum = 0;
            for (int i = l; i <= r; ++i)
            {
                sum += sequence[i];
            }
            results.push_back(sum);
        }
    }

    for (long long result : results)
    {
        cout << result << endl;
    }

    return 0;
}
