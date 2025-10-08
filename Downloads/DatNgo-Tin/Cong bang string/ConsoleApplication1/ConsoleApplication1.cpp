//Tim so cac so co tong chu so chan va tong cac so thoa man yeu cau do (gioi han: 10 ^ 200)
#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
	string r = "";
	short as = a.size() - 1, bs = b.size() - 1;
	a = '0' + a + '0', b = '0' + b + '0'; //Them so 0 phia truoc cho truong hop ket qua nhieu hon 1 don vi so voi chuoi co do dai lon hon, them so 0 phia sau de cong o hang don vi
	char res[200];
	int iter = max(as + 1, bs + 1); //Thiet lap chi so de cong tu hang don vi

	//Them |as - bs| so 0 vao chuoi co do dai ngan hon de thuc hien phep cong
	if (as > bs)
		for (int i = 1; i <= as - bs; ++i)
			b = '0' + b; 
	else if (as < bs)
		for (int i = 1; i <= bs - as; ++i)
			a = '0' + a; 

	for (int i = iter; i >= 0; --i)
		res[i] = char((int(a[i]) + int(b[i]) - 96 + (int(a[i+1]) + int(b[i+1]) - 96) / 10) % 10 + 48); //Cong thuc tinh phep cong bang string

	for (int i = 0; i <= iter; ++i)
		r += res[i]; //Truyen ket qua vao bien output

	return r;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	string out = "";
	int n, c = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		int sum = 0;
		for (int i = 0; i < temp.size(); ++i)
			sum += int(temp[i]) - 48;

		if (sum % 2 == 0)
		{
			out = add(out, temp);
			++c;
		}
	}
	if (c == 0) cout << -1;
	else if (c > 0)
	{
		while (out[0] == '0')
			out.erase(0, 1);
		cout << c << ' ' << out;
	}
	return 0;
}