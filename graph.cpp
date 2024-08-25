#include "graph.h"

Graph::Graph()
{
	cout << "input vertex" << endl;
	cin >> V_num;
	cout << "input edges" << endl;
	cin >> E_num;
	adj.assign(V_num, vector<int>(0));
	cout << "input" << endl;
	for (int i = 0; i < E_num; i++)
	{
		int v, m;
		cin >> v >> m;
		adj[v].push_back(m);
		adj[m].push_back(v);    
	}
}

int Graph::degree(int key)
{
	return adj[key].size();
}

void Graph::addedge(int key1, int key2)
{
	adj[key1].push_back(key2);
	adj[key2].push_back(key1);
	E_num++;
}

void Graph::see()
{
	cout << V_num << ' ' << E_num << endl;
	for (int i = 0; i < V_num; i++)
	{
		cout << i << ':';
		for (int j : adj[i])
			cout << j << ' ';
		cout << endl;
	}
}

Depth_First_Search::Depth_First_Search(Graph* a, int s) :x(a), count(0), start(s)
{
	marked.assign(x->get_v(), false);
	marked[start] = true;
	DFS(start);
}

void Depth_First_Search::DFS(int s)
{
	marked[s] = true;
	count++;
	const auto& list = x->get_adj();
	for (int i : list[s])
	{
		if (!marked[i])
			DFS(i);
	}
}

void Depth_First_Paths::DFS(int s)
{
	marked[s] = true;
	const auto& list = x->get_adj();
	for (int i : list[s])
	{
		if (!marked[i])
		{
			rope[i] = s;
			DFS(i);
		}
	}
}

Depth_First_Paths::Depth_First_Paths(Graph* a, int s):x(a),start(s)
{
	marked.assign(x->get_v(), false);
	rope.resize(x->get_v());
	DFS(start);
}

vector<int> Depth_First_Paths::pathTo(int v)
{
	vector<int> res;
	if (!hasPathto(v)) 
		return res;
	int tem = v;
	while (tem != start)
	{
		res.insert(res.begin(), tem);
		tem = rope[tem];
	}
	res.insert(res.begin(), tem);
	return res;
}

void Breadth_First_Paths::BFS(int s)
{
	queue<int> candidate;
	candidate.push(s);
	const auto& list = x->get_adj();
	while (!candidate.empty())
	{
		int fro = candidate.front();
		marked[fro] = true;
		for (int i : list[fro])
		{
			if (!marked[i])
			{
				candidate.push(i);
				rope[i] = fro;
			}
		}
		candidate.pop();
	}
}

Breadth_First_Paths::Breadth_First_Paths(Graph* a, int s):x(a),start(s)
{
	marked.assign(x->get_v(), false);
	rope.resize(x->get_v());
	BFS(start);
}

vector<int> Breadth_First_Paths::pathTo(int v)
{
	vector<int> res;
	if (!hasPathto(v))
		return res;
	int tem = v;
	while (tem != start)
	{
		res.insert(res.begin(), tem);
		tem = rope[tem];
	}
	res.insert(res.begin(), tem);
	return res;
}

void Connected_Component::DFS(int s)
{
	marked[s] = true;
	const auto& list = x->get_adj();
	for (int i : list[s])
	{
		if (!marked[i])
			DFS(i);
	}
}

Connected_Component::Connected_Component(Graph* a):x(a)
{
	marked.assign(x->get_v(), false);
	count = 0;
	for (int i = 0; i < marked.size(); i++)
	{
		if (!marked[i])
		{
			DFS(i);
			count++;
		}
	}
}

void Is_Circle::DFS(int s, int from)
{
	marked[s] = true;
	const auto& list = x->get_adj();
	for (int i : list[s])
	{
		if (i == from)
			continue;
		if (!marked[i])
			DFS(i,s);
		else
		{
			cycle = true;
			return;
		}
	}
}

Is_Circle::Is_Circle(Graph* a):x(a)
{
	marked.assign(x->get_v(), false);
	cycle = false;
	for (int i = 0; i < marked.size(); i++)
	{
		if (cycle == true)
			return;
		if (!marked[i])
		{
			DFS(i,INT_MIN);
		}
	}
}

void Is_Twocolor::BFS(int s)
{
	queue<int> candidate;
	candidate.push(s);
	color[s] = 1;
	const auto& list = x->get_adj();
	while (!candidate.empty())
	{
		int fro = candidate.front();
		for (int i : list[fro])
		{
			if (color[i]==0)
			{
				candidate.push(i);
				if (color[fro] == 1)
					color[i] = 2;
				else
					color[i] = 1;
			}
			else if (color[i] == color[fro])
			{
				check = false;
				return;
			}
		}
		candidate.pop();
	}
}

Is_Twocolor::Is_Twocolor(Graph* a):x(a)
{
	check = true;
	color.assign(x->get_v(), 0);//0:unchecked  1:red  2:black
	for (int i = 0; i < color.size(); i++)
	{
		if (check == false)
			return;
		if (color[i]==0)
			BFS(i);
	}
}

