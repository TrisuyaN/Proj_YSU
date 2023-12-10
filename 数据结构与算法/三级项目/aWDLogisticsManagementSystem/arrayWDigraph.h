
// arrayWDigraph����ʵ�֣�������ӻ�ɾ���㡢�ߡ������������·����Ѱ����ͨ���ȹ��ܣ����ϲ�Ӧ�ÿ���
// ģ���ຯ������ʵ�ֲ�ֵ�����tpp�ļ�

#ifndef arrayWDigraph_
#define arrayWDigraph_

#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <queue>
#include <algorithm>
#include "graph.h"
#include "edge.h"
#include "node.h"
#include "vertexIterator.h"

template<class T>
class arrayWDigraph : public graph<T> {

protected:
    /// ͼ���ݽṹ����
    // ���㼰����ͨ��ϵ�Ľṹ�壨n_vertex��ǿ���ڵ����ͨ��ϵ�����Ǳߵ���Ϣ��
	struct Vertex {
		int node_id; // �ڵ���
		vector<Node<T>> conn_vertices; // �ڵ���ͨ�Ľڵ㼯��
	};
	int n_vertex;   // ������
	int n_edge; // ����
	vector<Vertex> G; // �洢ͼ�еıߣ����õ�͵�֮��Ĺ�ϵVertex�ṹ����,����ڵ�1��G[1].conn_vertices���洢����ͨ�㣬��Ч�ڽڵ�1�ĳ��ߣ�
	vector<NodeInfo> V; // �洢ͼ�еĵ� // ע��GV�еĵ�������ͬ�ڽڵ��node_id����ҪgetIndex��������NodeInfo��node_id��ţ�����ɶ�����ȡV<NodeInfo>�ж�Ӧ������������Ӧ��V�Ĵ洢�ṹ��

    /// �෽������ʹ�õ��Ĺ�������
    const T INF = 9999999; // ����infiniteֵ
    //const T INF = std::numeric_limits<T>::max(); // ����infiniteֵ
	int* vis; // �Ƿ���ʣ�Ѱ·�㷨����
	int length; // ·������
	int** path_floyd; // �������µ�·��
	T** dis_floyd; // �������µľ���

	// dijkstraר�ñ���
	bool* is_reachable; // ĳ���Ƿ�ɴ�
	T* dis_dijkstra; // ��ĳ������ٷ���
    int* path_dijkstra; // ����·��
	stack<int> path_stack_dijkstra; // ����·�����������


public:
    /// arrayWDigraph�������������ຯ������������ʵ���ӷ�����ʵ����arrayWDigraph_basic.tpp��
    // ���ຯ��ʵ��
    explicit arrayWDigraph(int n_vertex_primary);
	~arrayWDigraph(){};
    int numberOfVertices() const {return n_vertex;}; // ��ȡ��ĸ���
    int numberOfEdges() const {return n_edge;}; // ��ȡ�ߵĸ���
    bool existsEdge(int vertex_in_id, int vertex_out_id) const; // �ж��Ƿ���ڱ�a->vertex_out_id
    void insertEdge(edge<T>* Edge); // �����
    bool eraseEdge(int v1, int v2); // ɾ����
    int degree(int v) const {return indegree(v) + outdegree(v);}; // ��ȡ��
    int indegree(int v) const {return V[v].in_degree;}; // ��ȡ���
    int outdegree(int v) const {return V[v].out_degree;}; // ��ȡ����
    bool directed()  const { return true; }; // �Ƿ�Ϊ����ͼ
    bool weighted()  const { return true; }; // �Ƿ�Ϊ��Ȩͼ


    // ʵ�û����Ӻ�����ͼ�㷨
    int _indegree(int x) {return indegree(getIndex(x));} // ��ȡ����ӷ���
    int _outdegree(int x) {return outdegree(getIndex(x));} // ��ȡ�����ӷ���
	int getIndex(int x); // ��ȡ���Ϊx�ĵ������
	bool existVertex(int node_id); // �ж��Ƿ��Ѿ����ڵ�v
	bool isEdgeLegal(int v1, int v2); // �жϱ�v1->v2�Ƿ�Ϸ�
	bool isVertexLegal(int node_id); // �жϵ�v�Ƿ�Ϸ�
	bool isWeightLegal(T weight); // �ж�Ȩֵ�Ƿ�Ϸ�
    void updateWeight(int vertex_in_id, int vertex_out_id, T new_weight); // ����Ȩֵ
    void addVertexSingle(int node_id, string node_info_name); // ���ӵ�
    void addVertex(); // ��Ӷ����
    void addVertex(int x); // ��ӵ����㣨���غ�����
    void deleteVertexSingle(int node_id); // ɾ����
    void deleteVertex(); // ɾ������ص�
    void addEdge(); // ���·
    void deleteEdge(); // ɾ��·
    void connectedSets(); // �����ͨ��
    void outputG(); // �����ǰͼ���б�
    void outputV(); // �����ǰͼ���е�
    void clearAllFiles(); // �����ļ��洢����Ϣ

	// �������������ʵ��
	class myIterator : public vertexIterator<T> {
	public:
		myIterator(Vertex& thelist) { // �������ã���С����
			newlist = thelist.conn_vertices;
			size = newlist.size() - 1; // ��ʼ��
			cur = 0;
		};
		int next() { // ȡ����ǰ��ָ���һ��
			if (cur > size)return 0; // ��ֹ
			int nextVertex = newlist[cur].node_id; // ȡ��Ȩֵ���±�
			cur++;//�α����
			return nextVertex;
		};
		int next(T& theWeight) {
			if (cur > size)return 0; // ��ֹ
			int nextVertex = newlist[cur].node_id; // ȡ���±�
			theWeight = newlist[cur].node_weight; // ȡ��Ȩֵ����ŵ��������ò���
			cur++; // �α����
			return nextVertex;
		};
		int next(T& theWeight, int& pos) {
			if (cur > size) return 0; // ��ֹ
			int nextVertex = newlist[cur].node_id; // ȡ���±�
			theWeight = newlist[cur].node_weight; // ȡ��Ȩֵ����ŵ��������ò���
			pos = cur++; // �α����
			return nextVertex;
		};
		void reset() { cur = 0; } // �����α�
	protected:
		vector<Node<T>> newlist;
		int x;
		int cur;
		int size;
	};

	// ͼ��������Աʵ��
	myIterator* iterator(int node_id) {
		if (isVertexLegal(node_id)) {
			return new myIterator(G[getIndex(node_id)]); // Ϊ���д���߱���Ϊ�����޷�ʹ�������е�nodes
		}
	};


    /// DFS��ʵ����arrayWDigraph_dfs.tpp��
    void rDFS(int start, int label);// ��DFS����
    void sDFS(int start, int label); //��dfs����
	void customizedDFS(int start, int label);//�Դ��ĵ�����dfs
	void DFS(int start, int label);//�α��ĵ�������DFS
    void DFSPerformCompare(); // dfs���ܲ���


    /// �ļ�������ʵ����arrayWDigraph_file_io.tpp��
    T stringToT(const string& str); // ��stringת��ΪT�����ڴ��ļ���ȡʱʹ��
	string getFirstPart(string s); // ���ص�һ���ֵ��ַ���
	string getSecondPart(string s); // ���صڶ����ֵ��ַ���
	string getThirdPart(string s); // ���ص������ֵ��ַ���
	int locateFirstBlank(string s); // ���ص�һ���ո�λ�õ��ַ�������
	int locateSecondBlank(string s); // ���صڶ����ո�λ�õ��ַ�������
    void updateEdgeWeight(int x, int y, T z); // ���ļ��и���Ȩֵ
    void addVertexFile(int x, string y); // ���ļ���д���x
    void deleteVertexFile(int x); // ɾ������ļ�����
    void addEdgeFile(int x, int y, T z); // ���ļ���д���x->y
    void deleteEdgeFile(int x, int y); // ɾ��·���ļ�����


    /// ��������㷨��ʵ����arrayWDigraph_topo.tpp��
    void _topologicalSorting(); // ��������
    void topoRank(); // �������򷽷�


    /// ·�����ͼ�㷨��ʵ����arrayWDigraph_path.tpp��
    void floydGetPath(); // ���·��������floydǰ�˺���
    void _floydPrintPath(); // ��ӡ���·��������_floyd�������н���ݹ����
    void _floyd_PrintPath(int i, int j); // ��ӡ���·���ӷ���
    void _floyd(); // ���������㷨

    void dijkstraGetPath(); // ���·��������dijkstraǰ�˺���
    void _dijkstra(int start); // Dijkstra�㷨���Ĳ��֣���������ʼ�㵽��������������·������Դ�������浽dis_dijkstra������
    T* _shortPathDijkstra(int start, int end); // �㷨�м�㣬��ʼ����Ҫ���ݣ��쳣����Ԥ����·��ϸ�����ݵ�
    void _dijkstraResult(int start, int end); // �˺�����ȡĿ���յ�����·�������

    T _aStarHeuristic(int current, int goal); // ��������
    vector<int> _aStar(int start, int end); // �����㷨
    void AStarGetPath(); // A*Ѱ· ǰ�˺���

    void _shortPathVia(int start, int through, int end);
    void shortPathVia(); // �������ͨ��ĳ������·��


    /// ��ʼ����غ�����ʵ����arrayWDigraph_init.tpp��
    void clearProgramData(); // ���ͼ
    void autoInitFromFile1(); // �ļ���ʼ��1
    void autoInitFromFile2(); // �ļ���ʼ��2
    void init(); // ��ʼ��
};


// ʵ���ļ���.tpp���İ���
#include "arrayWDigraph_basic.tpp"
#include "arrayWDigraph_file_io.tpp"
#include "arrayWDigraph_init.tpp"
#include "arrayWDigraph_path.tpp"
#include "arrayWDigraph_dfs.tpp"
#include "arrayWDigraph_topo.tpp"


#endif
