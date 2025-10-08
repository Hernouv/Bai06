#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> record;
//rock paper scissors
int rps()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 2 and it.second == 1) or (it.first == 3 and it.second == 2) or (it.first == 1 and it.second == 3))
			res++;
	return res;
}
//rock scissors paper
int rsp()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 3 and it.second == 1) or (it.first == 2 and it.second == 3) or (it.first == 1 and it.second == 2))
			res++;
	return res;
}
//paper rock scissors
int prs()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 2 and it.second == 3) or (it.first == 3 and it.second == 1) or (it.first == 1 and it.second == 2))
			res++;
	return res;
}
//paper scissors rock
int psr()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 2 and it.second == 1) or (it.first == 3 and it.second == 2) or (it.first == 1 and it.second == 3))
			res++;
	return res;
}
//scissors paper rock
int spr()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 2 and it.second == 3) or (it.first == 3 and it.second == 1) or (it.first == 1 and it.second == 2))
			res++;
	return res;
}
//scissors rock paper
int srp()
{
	int res = 0;
	for (auto it : record)
		if ((it.first == 2 and it.second == 1) or (it.first == 3 and it.second == 2) or (it.first == 1 and it.second == 3))
			res++;
	return res;
}

int main()
{
	freopen("rochambeau.inp", "r", stdin);
	freopen("rochambeau.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int cnt, win = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		record.emplace_back(t1, t2);
	}
	win = max(win, rps());
	win = max(win, rsp());
	win = max(win, prs());
	win = max(win, psr());
	win = max(win, spr());
	win = max(win, srp());
	cout << win;
	return 0;
}