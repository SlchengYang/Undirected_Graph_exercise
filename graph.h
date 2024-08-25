#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Ϊ���ʹ�����Ĭ�Ͻڵ�key����int��val=key
//���val��=key��Ҫ�ٽ�һ�ű�洢val�������鷳Щ��
//template<T>
//���⻹�к���Ҫ�ĺ��ԣ�����Ĭ��key���������벢�ݲ�����ɾ������
//����key�ܷ�ɢ���Ҵ���ɾ����������set�洢key֮��Ĺ�ϵ����map�洢key��val֮��Ĺ�ϵ
//������ʱɾ����֮�����ı�Ҳ��һ�������ˣ������ѡ��ߡ���Ϊһ��ʵ�壬��ͬkey���С�

//���ϣ����ǵ��㷨�ļ���ԣ�����಻���κ���ʽ�İ�ȫ��飬����ʾ��
//����һ������ͼ
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
	vector<bool> marked;//��¼ÿ���ڵ��Ƿ���start����ͨ
	Graph* x;
	int start;
	int count;//��start����ͨ�Ķ���������������
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
	vector<int> rope;//��¼��һ�ε���ĳ���ڵ�ʱ����ǰ��ڵ�
	vector<bool> marked;//��¼ÿ���ڵ��Ƿ���start����ͨ
	void DFS(int s);
public:
	Depth_First_Paths(Graph* a, int s);
	bool hasPathto(int v) { return marked[v]; }
	vector<int> pathTo(int v);//��·�������ȷ���v��·����������˳���йأ���ʵ�����塣
};

class Breadth_First_Paths
{
private:
	Graph* x;
	int start;
	vector<int> rope;//��¼��һ�ε���ĳ���ڵ�ʱ����ǰ��ڵ�
	vector<bool> marked;
	void BFS(int s);
public:
	Breadth_First_Paths(Graph* a, int s);
	bool hasPathto(int v) { return marked[v]; }
	vector<int> pathTo(int v);//���·��
};

class Connected_Component//��������
{
private:
	Graph* x;
	int count;//��ͨ��������
	vector<bool> marked;
	void DFS(int s);
public:
	Connected_Component(Graph* a);
	int get_cc() { return count; }
};

class Is_Circle//�������Ѽ����л�ͼ
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

class Is_Twocolor//���ڹ��Ѽ���˫ɫͼ
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