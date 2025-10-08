#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[6][6];
int max_val = 0;

int dfs(int index, int used_rows, int used_cols)
{
    if (index == n * m)
    {
        return 0;
    }

    int row = index / m;
    int col = index % m;
    int result = dfs(index + 1, used_rows, used_cols);

    if (grid[row][col] == '.' && !(used_rows & (1 << row)) && !(used_cols & (1 << col)))
    {
        int placed = 1 + dfs(index + 1, used_rows | (1 << row), used_cols | (1 << col));
        result = max(result, placed);
    }

    return result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = s[j];
        }
    }

    int answer = dfs(0, 0, 0);
    cout << answer;
}
