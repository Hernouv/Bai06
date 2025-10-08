#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> dayso;
    deque<int> xuly;

    int n, so;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> so;
        dayso.push(so);
    }
    while (dayso.empty() == false)
    {
        int tam = dayso.front();
        if (dayso.front() % 2 == 0)
            xuly.push_front(tam);
        else
            xuly.push_back(tam);
        dayso.pop();
    }
    while (xuly.empty() == false)
    {
        cout << xuly.back() << ' ';
        xuly.pop_back();
    }
    return 0;
}