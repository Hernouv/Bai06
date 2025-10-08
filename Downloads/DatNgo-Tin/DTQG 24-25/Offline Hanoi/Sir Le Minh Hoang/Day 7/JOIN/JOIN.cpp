#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("JOIN.INP", "r"))
    {
        freopen("JOIN.INP", "r", stdin);
        freopen("JOIN.OUT", "w", stdout);
    }

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<long long> stack;
    long long max_val = 0;

    for (int i = 0; i < N; i++)
    {
        stack.push_back(A[i]);

        if (A[i] > max_val)
            max_val = A[i];

        while (stack.size() >= 2 and stack.back() == stack[stack.size() - 2])
        {
            long long merged = stack.back() * 2;
            stack.pop_back();
            stack.pop_back();
            stack.push_back(merged);
            if (merged > max_val)
                max_val = merged;
        }
    }
    cout << max_val;
}
