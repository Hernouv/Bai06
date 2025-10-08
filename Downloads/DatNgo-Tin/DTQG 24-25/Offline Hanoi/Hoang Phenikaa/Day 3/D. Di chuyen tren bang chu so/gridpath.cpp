#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    string s;
    cin >> s;

    int total = n * n;

    vector<bitset<10000>> digit_masks(10, bitset<10000>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c = grid[i][j];
            int d = c - '0';
            int pos = i * n + j;
            digit_masks[d].set(pos);
        }
    }

    bitset<10000> not_first_col_mask;
    bitset<10000> not_last_col_mask;
    not_first_col_mask.reset();
    not_last_col_mask.reset();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int pos = i * n + j;
            if (j != 0)
                not_first_col_mask.set(pos);
            if (j != n - 1)
                not_last_col_mask.set(pos);
        }
    }

    if (s.empty())
    {
        cout << 0;
        return 0;
    }

    int first_digit = s[0] - '0';
    bitset<10000> prev_mask = digit_masks[first_digit];
    if (prev_mask.none())
    {
        cout << 0;
        return 0;
    }

    int max_i = 0;
    if (prev_mask.any())
        max_i = 1;
    for (int k = 1; k < s.size(); k++)
    {
        int current_digit = s[k] - '0';
        bitset<10000> left_shifted = (prev_mask << 1) & not_first_col_mask;
        bitset<10000> right_shifted = (prev_mask >> 1) & not_last_col_mask;
        bitset<10000> up_shifted = (prev_mask << n);
        bitset<10000> down_shifted = (prev_mask >> n);
        left_shifted &= bitset<10000>().set();
        right_shifted &= bitset<10000>().set();
        up_shifted &= bitset<10000>().set();
        down_shifted &= bitset<10000>().set();
        bitset<10000> neighbor_mask = left_shifted | right_shifted | up_shifted | down_shifted;
        bitset<10000> curr_mask = neighbor_mask & digit_masks[current_digit];
        if (curr_mask.none())
        {
            cout << max_i;
            return 0;
        }
        prev_mask = curr_mask;
        max_i++;
    }
    cout << max_i;
}