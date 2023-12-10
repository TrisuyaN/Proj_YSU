
// graph�������

#ifndef graph_
#define graph_

#include"edge.h"
#include"vertexIterator.h"

template<class T>
class graph{
public:
    virtual ~graph() {}
    virtual int numberOfVertices() const = 0;//��ĸ���
    virtual int numberOfEdges() const = 0;//�ߵĸ���
    virtual bool existsEdge(int, int) const = 0;//�ж��Ƿ���ڴ�ǰ��㵽�����ı�
    virtual void insertEdge(edge<T>*) = 0;//�����
    virtual bool eraseEdge(int, int) = 0;//ɾ����
    virtual int degree(int) const = 0;//��
    virtual int indegree(int) const = 0;//���
    virtual int outdegree(int) const = 0;//����
    virtual bool directed() const = 0;//����
    virtual bool weighted() const = 0;//Ȩ��
    virtual vertexIterator<T>* iterator(int) = 0;//������
};

#endif
