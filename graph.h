#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//为降低代码量默认节点key都是int，val=key
//如何val！=key还要再建一张表存储val，输入麻烦些。
//template<T>
//另外还有很重要的忽略，我们默认key是连续输入并暂不考虑删除的事
//假如key很分散并且存在删除，不妨用set存储key之间的关系，用map存储key与val之间的关系
//不过这时删除与之关联的边也是一件难事了，不妨把“边”设为一种实体，不同key共有。

//综上，考虑到算法的简洁性，这个类不作任何形式的安全检查，仅作示例
//这是一个无向图
class Graph
{
private:
	int V_num;
	int E_num;
	//vector<T> val;
	vector<vector<int>> adj;

public:
	Graph();
	int degree(int key);
	void addedge(int key1, int key2);
	vector<vector<int>> get_adj(){ return adj; }
	int get_v() { return V_num; }
	int get_e() { return E_num; }
	void see();
};

class Depth_First_Search
{
private:
	vector<bool> marked;//记录每个节点是否与start相连通
	Graph* x;
	int start;
	int count;//与start相连通的定点数（包含本身）
public:
	Depth_First_Search(Graph* a, int s);
	void DFS(int s);
	int get_start() { return start; }
	int get_count() { return count; }
	bool mark(int v) { return marked[v]; }
};

class  Depth_First_Paths
{
private:
	Graph* x;
	int start;
	vector<int> rope;//记录第一次到达某个节点时他的前序节点
	vector<bool> marked;//记录每个节点是否与start相连通
	void DFS(int s);
public:
	Depth_First_Paths(Graph* a, int s);
	bool hasPathto(int v) { return marked[v]; }
	vector<int> pathTo(int v);//此路径是最先发现v的路径，和输入顺序有关，无实际意义。
};

class Breadth_First_Paths
{
private:
	Graph* x;
	int start;
	vector<int> rope;//记录第一次到达某个节点时他的前序节点
	vector<bool> marked;
	void BFS(int s);
public:
	Breadth_First_Paths(Graph* a, int s);
	bool hasPathto(int v) { return marked[v]; }
	vector<int> pathTo(int v);//最短路径
};

class Connected_Component//基于深搜
{
private:
	Graph* x;
	int count;//连通分量个数
	vector<bool> marked;
	void DFS(int s);
public:
	Connected_Component(Graph* a);
	int get_cc() { return count; }
};

class Is_Circle//基于深搜鉴别有环图
{
private:
	Graph* x;
	vector<bool> marked;
	void DFS(int s, int from);
	bool cycle;
public:
	Is_Circle(Graph* a);
	bool get_cycle() { return cycle; }
};

class Is_Twocolor//基于广搜鉴别双色图
{
private:
	Graph* x;
	vector<int> color;
	bool check;
	void BFS(int s);
public:
	Is_Twocolor(Graph* a);
	bool get_tc() { return check; }
};