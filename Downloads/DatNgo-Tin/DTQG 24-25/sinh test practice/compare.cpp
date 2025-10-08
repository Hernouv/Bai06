#include <bits/stdc++.h>
using namespace std;

const string NAME = "demo";

const int NTEST = 1000;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int randInt(int l, int r)
{
    return l + rand() % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        system(((string) "gen.cpp").c_str());
        system((NAME + ".cpp").c_str());
        system((NAME + "_naive.cpp").c_str());

        if (system(("fc /w " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
