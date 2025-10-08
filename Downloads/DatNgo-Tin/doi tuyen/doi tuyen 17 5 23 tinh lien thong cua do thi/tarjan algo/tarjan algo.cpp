#include <bits/stdc++.h>
using namespace std;

// esvi edge_starting_vertex_index
// eevi edge_ending_vertex_index
// iatv index_assigned_to_vertex
// lvvi lowest_visitable_vertex_index
// vocc vertices_of_connected_component
// apocc already_part_of_connected_component
// ccno connected_component_number
// nv no_of_vertices
// ne no_of_edges
// ia index_assigner

vector<int> graph[10001];
int iatv[10001], lvvi[10001], nv, ne, ccno = 0, ia = 0;
stack<int> vocc;
bool apocc[10001];

void tarjan(int index)
{
	ia++;
	iatv[index] = lvvi[index] = ia;
	vocc.push(ia);

	for (auto v : graph[index])
	{
		if (!apocc[v])
		{
			if (iatv[v])
				lvvi[index] = min(lvvi[index], iatv[v]);
			else
			{
				tarjan(v);
				lvvi[index] = min(lvvi[index], lvvi[v]);
			}
		}
	}

	// display
	if (iatv[index] == lvvi[index])
	{
		ccno++;
		cout << "Connected component " << ccno << ": ";
		int t;
		do
		{
			t = vocc.top();
			apocc[t] = true;
			cout << t << ' ';
			vocc.pop();
		} while (t != index);
		cout << endl;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	memset(apocc, false, sizeof(apocc));
	cin >> nv >> ne;
	for (int i = 1; i <= ne; ++i)
	{
		int esvi, eevi;
		cin >> esvi >> eevi;
		graph[esvi].push_back(eevi);
	}

	for (int i = 1; i <= nv; ++i)
		if (!apocc[i])
			tarjan(i);

	for (int i = 1; i <= nv; ++i)
		cout << iatv[i] << ' ' << lvvi[i] << '\n';
	return 0;
}