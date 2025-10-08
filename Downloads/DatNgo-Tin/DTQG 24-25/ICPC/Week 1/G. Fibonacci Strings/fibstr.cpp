#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

long long F(int n, vector<long long> &lengths, vector<long long> &counts)
{
    if (n == 0)
        return 0; // F(0)
    if (n == 1)
        return 1; // F(1)

    long long beauty = 0;

    for (int i = 0; i <= n; ++i)
    {
        long long length = lengths[i];
        long long count = counts[i];
        // Each substring contributes its weight
        // Count of substrings of length `length` = length * (length + 1) / 2
        long long num_substrings = (length * (length + 1) / 2) % MOD;
        // Weight contribution = count of 1's * num_substrings
        beauty = (beauty + (count * num_substrings) % MOD) % MOD;
    }

    return beauty;
}

void compute_fibonacci(int n, vector<long long> &lengths, vector<long long> &counts)
{
    lengths[0] = 1; // length of "0"
    lengths[1] = 1; // length of "1"
    counts[0] = 0;  // count of 1's in "0"
    counts[1] = 1;  // count of 1's in "1"

    for (int i = 2; i <= n; ++i)
    {
        lengths[i] = (lengths[i - 2] + lengths[i - 1]) % MOD;
        counts[i] = (counts[i - 2] + counts[i - 1]) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> lengths(100001); // Lengths of f(i)
    vector<long long> counts(100001);  // Counts of 1's in f(i)

    // Precompute lengths and counts up to maximum needed
    int max_n = 0;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        if (n > max_n)
        {
            max_n = n;
        }
    }

    compute_fibonacci(max_n, lengths, counts);

    // Now compute F(n) for each test case
    cin.clear();
    cin.seekg(0, ios::beg);
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << F(n, lengths, counts) << "\n";
    }

    return 0;
}
