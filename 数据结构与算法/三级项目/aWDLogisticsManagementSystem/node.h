
// �ڵ�node��ͽڵ���Ϣ��

#ifndef node_
#define node_

#include<iostream>
#include <utility>
using namespace std;

template<class T>
class Node {
public:
    int node_id; // �õ�ı��
    T node_weight; // Ȩֵ����Ϊ���ӵ��˵�ı�Ȩֵ

	Node(int num, int we=0) {
        node_id = num;
        node_weight = we;
	}

	int getn() {return node_id;}
	int getw() {return node_weight;}

    // ����==����������ȽϹ��򣬱����ͬ�Ľڵ㼴Ϊͬһ�ڵ㣩
	bool operator==(int y) {
		if (y == this->node_id) return true;
		else return false;
	}
};



// �ڵ���Ϣ��
class NodeInfo {
public:
    int node_id; // �ڵ���
	int in_degree; // �õ�����
	int out_degree; // �õ�ĳ���
	string name; // �õ�������ĵ���������

	NodeInfo(int nodeinfo_id = 0, string nodeinfo_name = "", int nodeinfo_in_degree = 0, int nodeinfo_out_degree = 0 ){
        name = std::move(nodeinfo_name); // ʹ���ƶ������Ż�
        node_id = nodeinfo_id;
        in_degree = nodeinfo_in_degree;
        out_degree = nodeinfo_out_degree;
	}
};

#endif