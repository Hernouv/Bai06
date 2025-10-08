#include <bits/stdc++.h>
using namespace std;

string inp;
int vowel_cnt, consonant_cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);
    cin >> inp;
    for (char x : inp)
    {
        if (x == 'u' or x == 'o' or x == 'e' or x == 'a' or x == 'i')
            vowel_cnt++;
        else
            consonant_cnt++;
    }
    cout << vowel_cnt * consonant_cnt;
    return 0;
}