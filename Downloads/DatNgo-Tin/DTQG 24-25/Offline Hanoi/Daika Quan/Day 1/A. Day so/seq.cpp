#include <bits/stdc++.h>
using namespace std;

#define int long long
#define whole(_name) _name.begin(), _name.end()

class SortedList
{
public:
    void insert(int value)
    {
        auto it = lower_bound(whole(data), value);
        data.insert(it, value);
    }

    int countInRange(int lower, int upper)
    {
        return upper_bound(whole(data), upper) - lower_bound(whole(data), lower);
    }

private:
    vector<int> data;
};

int countSubarraysInRange(const vector<int> &A, int L, int R)
{
    int prefix_sum = 0;
    SortedList prefix_sums;
    prefix_sums.insert(0);
    int count = 0;

    for (int num : A)
    {
        prefix_sum += num;

        int lower_bound = prefix_sum - R;
        int upper_bound = prefix_sum - L;

        count += prefix_sums.countInRange(lower_bound, upper_bound);

        prefix_sums.insert(prefix_sum);
    }

    return count;
}

int32_t main()
{
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> A(n);
    int tnum;
    for (int i = 0; i < n; ++i)
    {
        cin >> tnum;
        A[i] = tnum;
    }

    int result = countSubarraysInRange(A, L, R);
    cout << result;

    return 0;
}
