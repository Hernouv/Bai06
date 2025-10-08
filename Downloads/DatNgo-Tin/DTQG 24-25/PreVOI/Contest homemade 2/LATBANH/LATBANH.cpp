#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> merge_intervals(vector<pair<int, int>> intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    merged.emplace_back(intervals[0].first, intervals[0].second);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first <= merged.back().second)
        {
            merged.back().second = max(merged.back().second, intervals[i].second);
        }
        else
        {
            merged.emplace_back(intervals[i].first, intervals[i].second);
        }
    }
    return merged;
}

vector<pair<int, int>> intersect_intervals(const vector<pair<int, int>> &A, const vector<pair<int, int>> &B)
{
    vector<pair<int, int>> intersection;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        int start = max(A[i].first, B[j].first);
        int end = min(A[i].second, B[j].second);
        if (start <= end)
        {
            intersection.emplace_back(start, end);
        }
        if (A[i].second < B[j].second)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return intersection;
}

bool is_allowed(int t, const vector<pair<int, int>> &allowed)
{
    int left = 0, right = allowed.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (allowed[mid].first <= t && t <= allowed[mid].second)
        {
            return true;
        }
        else if (t < allowed[mid].first)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("LATBANH.INP", "r"))
    {
        freopen("LATBANH.INP", "r", stdin);
        freopen("LATBANH.OUT", "w", stdout);
    }
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> intervals(K);
    for (int i = 0; i < K; i++)
        cin >> intervals[i].first >> intervals[i].second;
    vector<pair<int, int>> allowed = merge_intervals(intervals);
    bool m1 = false;
    for (auto &[l, r] : allowed)
    {
        if (l <= N && N <= r)
        {
            m1 = true;
            break;
        }
    }
    if (m1)
    {
        cout << "1";
        return 0;
    }
    vector<pair<int, int>> A;
    for (auto &[l, r] : allowed)
    {
        int start = max(l, 0);
        int end = min(r, N);
        if (start <= end)
        {
            A.emplace_back(start, end);
        }
    }
    vector<pair<int, int>> B_shifted;
    for (auto &[l, r] : allowed)
    {
        int start = max(l - N, 0);
        int end = min(r - N, N);
        if (start <= end)
        {
            B_shifted.emplace_back(start, end);
        }
    }
    B_shifted = merge_intervals(B_shifted);
    vector<pair<int, int>> C = intersect_intervals(A, B_shifted);
    bool m2 = false;
    vector<int> f_list;
    for (auto &[l, r] : C)
    {
        m2 = true;
        break;
    }
    if (m2)
    {
        vector<int> possible_f;
        for (auto &[l, r] : C)
        {
            possible_f.emplace_back(l);
            possible_f.emplace_back(r);
        }
        sort(possible_f.begin(), possible_f.end());
        possible_f.erase(unique(possible_f.begin(), possible_f.end()), possible_f.end());
        vector<pair<int, int>> C_sorted = C;
        sort(C_sorted.begin(), C_sorted.end(), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool
             { return a.second < b.second; });
        int k_max = 0;
        int last_f = -1e9;
        for (auto &[l, r] : C_sorted)
        {
            if (l > last_f + N)
            {
                int f = l;
                k_max++;
                last_f = f;
            }
        }
        if (k_max >= 1)
        {
            cout << "2";
            return 0;
        }
    }
    vector<int> allowed_times;
    for (auto &[l, r] : A)
    {
        for (int t = l; t <= r && t <= N; t++)
        {
            allowed_times.emplace_back(t);
            if (r - l > 1000)
            {
                break;
            }
        }
    }
    sort(allowed_times.begin(), allowed_times.end());
    allowed_times.erase(unique(allowed_times.begin(), allowed_times.end()), allowed_times.end());
    bool m3 = false;
    for (auto f1 : allowed_times)
    {
        for (auto f2 : allowed_times)
        {
            if (f2 <= f1)
                continue;
            int f3 = f2 + N - f1;
            if (f3 <= f2)
                continue;
            if (f3 > 2 * N)
                continue;
            bool allowed_f3 = false;
            for (auto &[l, r] : allowed)
            {
                if (l <= f3 && f3 <= r)
                {
                    allowed_f3 = true;
                    break;
                }
            }
            if (allowed_f3)
            {
                m3 = true;
                break;
            }
        }
        if (m3)
            break;
    }
    if (m3)
    {
        cout << "3";
        return 0;
    }
    vector<pair<int, int>> C_sorted_full = C;
    sort(C_sorted_full.begin(), C_sorted_full.end(), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool
         { return a.second < b.second; });
    int k_max_full = 0;
    int last_f_full = -1e9;
    for (auto &[l, r] : C_sorted_full)
    {
        if (l > last_f_full + N)
        {
            int f = l;
            k_max_full++;
            last_f_full = f;
        }
    }
    if (k_max_full >= 2)
    {
        cout << "4";
        return 0;
    }
    cout << "-1";
    return 0;
}
