#include <bits/stdc++.h>
using namespace std;

string inp;
bool connect[110][110];
char res[1010];

int calc(int x)
{
    if (res[x] == 'U' or res[x] == 'O' or res[x] == 'E' or res[x] == 'A' or res[x] == 'I')
        return 1;
    return 0;
}

vector<char> consonant;

int main()
{
    getline(cin, inp);

    for (int i = 0; i < 26; i++)
    {
        char ch = char(i + 'A');
        if (ch == 'A' or ch == 'U' or ch == 'I' or ch == 'O' or ch == 'E')
            continue;
        consonant.push_back(ch);
    }

    memset(connect, false, sizeof(connect));
    for (int i = 1; i < inp.size(); i++)
    {
        if (inp[i - 1] != ' ' and inp[i] != ' ')
        {
            int u = (int)(inp[i - 1] - 'A') + 1;
            int v = (int)(inp[i] - 'A') + 1;

            connect[u][v] = connect[v][u] = true;
        }
    }

    for (int i = 1; i <= 22; i++)
        for (int j = i + 1; j <= 23; j++)
            for (int k = j + 1; k <= 24; k++)
                for (int x = k + 1; x <= 25; x++)
                    for (int y = x + 1; y <= 26; y++)
                    {
                        for (int u = 1; u <= 26; u++)
                            res[u] = '6';
                        res[i] = 'A';
                        res[j] = 'E';
                        res[k] = 'I';
                        res[x] = 'O';
                        res[y] = 'U';

                        int cnt = 0;
                        for (int u = 1; u <= 26; u++)
                        {
                            if (res[u] != '6')
                                continue;
                            res[u] = consonant[cnt++];
                        }

                        bool flag = true;
                        for (int u = 1; u <= 26; u++)
                        {
                            for (int v = 1; v <= 26; v++)
                            {
                                if (connect[u][v] == true and calc(u) == calc(v))
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (flag == true)
                        {
                            for (char ch : inp)
                            {
                                if (ch == ' ')
                                    cout << ' ';
                                else
                                {
                                    int id = int(ch - 'A') + 1;
                                    cout << res[id];
                                }
                            }
                            return 0;
                        }
                    }
    cout << "impossible";
    return 0;
}