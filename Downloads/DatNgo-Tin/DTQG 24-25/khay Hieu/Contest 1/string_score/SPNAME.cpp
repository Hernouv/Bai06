#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(__) __.begin(), __.end()

int compute_lcp(const string &a, const string &b)
{
    int lcp = 0;
    int len = min(a.size(), b.size());
    while (lcp < len and a[lcp] == b[lcp])
        lcp++;
    return lcp;
}

ll max_score = 0;
vector<string> strings_sorted;
vector<string> reversed_strings_sorted;

// Recursive function to process each group of strings with a common prefix
void processNode(const vector<int> &group, int depth)
{
    if (group.size() < 2)
        return;

    // Find min_rev and max_rev in the group
    string min_rev = reversed_strings_sorted[group[0]];
    string max_rev = reversed_strings_sorted[group[0]];
    for (int i = 1; i < group.size(); i++)
    {
        if (reversed_strings_sorted[group[i]] < min_rev)
            min_rev = reversed_strings_sorted[group[i]];
        if (reversed_strings_sorted[group[i]] > max_rev)
            max_rev = reversed_strings_sorted[group[i]];
    }

    // Compute lcp_sz
    int lcp_sz = compute_lcp(min_rev, max_rev);

    // Compute score
    if (lcp_sz > 0)
    {
        ll score = (ll)group.size() * depth * lcp_sz;
        if (score > max_score)
            max_score = score;
    }

    // Sort the group by reversed strings
    vector<int> sorted_group = group;
    sort(whole(sorted_group), [&](const int a, const int b) -> bool
         { return reversed_strings_sorted[a] < reversed_strings_sorted[b]; });

    // Compute LCP array
    int M = sorted_group.size();
    vector<int> LCP;
    LCP.reserve(M - 1);
    for (int i = 1; i < M; i++)
    {
        LCP.push_back(compute_lcp(reversed_strings_sorted[sorted_group[i - 1]], reversed_strings_sorted[sorted_group[i]]));
    }

    // Find maximum |S| * lcp_sz using stack (Maximum Rectangle in Histogram approach)
    // We want to maximize |S| * lcp_sz, where |S| is the number of strings in the subset and lcp_sz is the minimum LCP in the subset
    // To do this, we treat the LCP array as heights and find the maximum rectangle area
    // where width corresponds to |S| - 1 and height corresponds to lcp_sz
    // Then, |S| = width + 1
    // Thus, the score is (width + 1) * lcp_sz
    // Finally, multiply by depth to get the total score
    vector<int> extended_LCP = LCP;
    extended_LCP.push_back(0);
    stack<int> s;
    int i = 0;
    while (i < extended_LCP.size())
    {
        if (s.empty() or extended_LCP[i] >= extended_LCP[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            int top = s.top();
            s.pop();
            int h = extended_LCP[top];
            int width = s.empty() ? i : i - s.top() - 1;
            ll current_score = (ll)(width + 1) * h * depth;
            if (current_score > max_score)
                max_score = current_score;
        }
    }

    // Now, split the group into subgroups based on the next character in the prefix
    // Only consider strings that have a character at the current depth
    // and group them by that character
    vector<vector<int>> subgroups;
    int start = 0;
    while (start < sorted_group.size())
    {
        // Check if the string has a character at the current depth
        if (depth >= strings_sorted[sorted_group[start]].size())
        {
            start++;
            continue;
        }
        char current_char = strings_sorted[sorted_group[start]][depth];
        int end = start + 1;
        while (end < sorted_group.size() and depth < strings_sorted[sorted_group[end]].size() and strings_sorted[sorted_group[end]][depth] == current_char)
        {
            end++;
        }
        if (end - start >= 2)
        {
            subgroups.emplace_back(vector<int>(sorted_group.begin() + start, sorted_group.begin() + end));
        }
        start = end;
    }

    // Recursively process each subgroup
    for (auto &subgroup : subgroups)
    {
        processNode(subgroup, depth + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> strings(N);
    for (int i = 0; i < N; i++)
    {
        cin >> strings[i];
    }

    sort(whole(strings));

    strings_sorted = strings;

    reversed_strings_sorted.resize(N);
    for (int i = 0; i < N; i++)
    {
        reversed_strings_sorted[i] = strings_sorted[i];
        reverse(whole(reversed_strings_sorted[i]));
    }

    vector<int> initial_group(N);
    for (int i = 0; i < N; i++)
        initial_group[i] = i;

    processNode(initial_group, 0);

    cout << max_score;
}
