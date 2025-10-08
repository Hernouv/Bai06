#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<long long>> a(m, vector<long long>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> height(n, 0);
    long long max_area = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r == 0)
            {
                height[c] = 1;
            }
            else
            {
                if (a[r][c] == a[r - 1][c])
                {
                    height[c] += 1;
                }
                else
                {
                    height[c] = 1;
                }
            }
        }

        int start = 0;
        while (start < n)
        {
            long long val = a[r][start];
            int end = start;

            while (end < n && a[r][end] == val)
            {
                end++;
            }
            int seg_len = end - start;

            {
                stack<int> st;
                for (int i = 0; i < seg_len; i++)
                {
                    while (!st.empty() && height[start + st.top()] > height[start + i])
                    {
                        int top_id = st.top();
                        st.pop();
                        int left = st.empty() ? 0 : st.top() + 1;
                        long long area = (long long)height[start + top_id] * (i - left);
                        if (area > max_area)
                        {
                            max_area = area;
                        }
                    }
                    st.push(i);
                }
                while (!st.empty())
                {
                    int top_id = st.top();
                    st.pop();
                    int left = st.empty() ? 0 : st.top() + 1;
                    long long area = (long long)height[start + top_id] * (seg_len - left);
                    if (area > max_area)
                    {
                        max_area = area;
                    }
                }
            }

            start = end;
        }
    }

    cout << max_area << "\n";

    return 0;
}
