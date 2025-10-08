#include <bits/stdc++.h>
using namespace std;

map<string, int> d;
string ans[370];

void initialize()
{
    d["Jan"] = 0;
    d["Feb"] = 31;
    d["Mar"] = 60;
    d["Apr"] = 91;
    d["May"] = 121;
    d["Jun"] = 152;
    d["Jul"] = 182;
    d["Aug"] = 213;
    d["Sep"] = 244;
    d["Oct"] = 274;
    d["Nov"] = 305;
    d["Dec"] = 335;

    for (int i = 21 + d["Jan"]; i <= 19 + d["Feb"]; ++i)
        ans[i] = "Aquarius";
    for (int i = 20 + d["Feb"]; i <= 20 + d["Mar"]; ++i)
        ans[i] = "Pisces";
    for (int i = 21 + d["Mar"]; i <= 20 + d["Apr"]; ++i)
        ans[i] = "Aries";
    for (int i = 21 + d["Apr"]; i <= 20 + d["May"]; ++i)
        ans[i] = "Taurus";
    for (int i = 21 + d["May"]; i <= 21 + d["Jun"]; ++i)
        ans[i] = "Gemini";
    for (int i = 22 + d["Jun"]; i <= 22 + d["Jul"]; ++i)
        ans[i] = "Cancer";
    for (int i = 23 + d["Jul"]; i <= 22 + d["Aug"]; ++i)
        ans[i] = "Leo";
    for (int i = 23 + d["Aug"]; i <= 21 + d["Sep"]; ++i)
        ans[i] = "Virgo";
    for (int i = 22 + d["Sep"]; i <= 22 + d["Oct"]; ++i)
        ans[i] = "Libra";
    for (int i = 23 + d["Oct"]; i <= 22 + d["Nov"]; ++i)
        ans[i] = "Scorpio";
    for (int i = 23 + d["Nov"]; i <= 21 + d["Dec"]; ++i)
        ans[i] = "Sagittarius";
    for (int i = 22 + d["Dec"]; i <= 31 + d["Dec"]; ++i)
        ans[i] = "Capricorn";
    for (int i = 1 + d["Jan"]; i <= 20 + d["Jan"]; ++i)
        ans[i] = "Capricorn";
}

void not_main()
{
    initialize();
    int t;
    cin >> t;
    int day;
    string month;
    while (t--)
    {
        cin >> day >> month;
        cout << ans[day + d[month]] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}