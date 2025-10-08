// liet ke so nguyen to
#include <bits/stdc++.h>
using namespace std;

bool arr[1000000 + 1];

int main()
{
    memset(arr, true, sizeof(arr));
    arr[1] = false;
    for (int i = 2; i <= 1000; ++i)
        if (arr[i] == true)
            for (int j = i * i; j <= 1000001; j += i)
                arr[j] = false;

    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
        if (arr[i] == true)
            cout << i << ' ';

    return 0;
}