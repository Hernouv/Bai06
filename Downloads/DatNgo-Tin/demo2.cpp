#include <bits/stdc++.h>
#define NAME "b1"
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r)
{
    return (l + rd() * 1LL * rd() % (r - l + 1));
}
void MakeTest()
{
    ofstream inp(NAME ".inp");
    int n = 6;
    inp << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        int x = Rand(0, 10), y = Rand(0, 10);
        inp << x << ' ' << y << '\n';
    }
}
const int NTest = 10000;
int main()
{
    for (int i = 1; i <= NTest; i++)
    {
        MakeTest();
        system(NAME "_trau.exe");
        system(NAME ".exe");
        /* Khi khong dung freopen
        system(NAME".exe <"NAME".inp >"NAME".out");
        system(NAME"_trau.exe < NAME".inp > "NAME".ans");
        */
        if (system("fc " NAME ".out " NAME ".ans") != 0)
        {
            cout << "Test " << i << ": Wrong!\n";
            return 0;
        }
        cout << "Test " << i << ": Correct!\n";
    }
}