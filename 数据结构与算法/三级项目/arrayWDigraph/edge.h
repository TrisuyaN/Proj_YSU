
// edge�ࣺ������Ȩͼ�ıߵ����ݽṹ��ģ�����TΪ��Ȩ�洢������

#ifndef edge_
#define edge_

#include<iostream>

using namespace std;

template<class T>
class edge {
public:
    int vertex_in;
    int vertex_out;
    T w;

    // ���캯����Ҫ��ʼ���յ�ͱ�Ȩ��������
	edge(int vertex_in_id = -1, int vertex_out_id = -1, T weight = 0) { vertex_in = vertex_in_id; vertex_out = vertex_out_id; w = weight; }
	~edge() {}

    // ��ȡ����˽�����ݵķ���
	int get_vertex_in_id() { return vertex_in; }
	int get_vertex_out_id() { return vertex_out; }
	T get_weight() { return w; }

    // ��׼���edge����Ϣ
	void output() { cout << "(" << vertex_in << "," << vertex_out << "," << w << ")"; }
};

#endif