#include <bits/stdc++.h>
using namespace std;
long long doicho(long long &a, long long &b)
{
	long long tam = a;
	a = b;
	b = tam;
}
long long x, y;
int main()
{
	long long x = 1, y = 2;
	doicho(x,y);
	cout << x << " " << y;
}