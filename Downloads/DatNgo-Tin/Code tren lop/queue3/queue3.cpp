#include <bits/stdc++.h>
using namespace std;

priority_queue<int> xuly;
char loai_yeucau;
int V;

int main()
{
    while (cin >> loai_yeucau)
    {
        if (loai_yeucau == '+')
        {
            cin >> V;
            xuly.push(V);
        }
        else if (loai_yeucau == '-')
        {
            int tam = xuly.top();
            while (xuly.top() == tam)
                xuly.pop();
        }
    }
    cout << xuly.size() << endl;
    while (xuly.empty() == false)
    {
        cout << xuly.top() << ' ';
        xuly.pop();
    }
    return 0;
}