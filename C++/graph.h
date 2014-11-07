#ifndef GRAPH_H_
#define GRAPH_H_
#define MAXVEX 100			//��󶥵���
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char VertexType;	//��������Ӧ���û�����
typedef int Boolean;            //Boolean �ǲ������ͣ���ֵ��TRUE ��FALSE
Boolean visited[MAXVEX];        //���ʱ�־����

typedef struct ArcNode		//�߱���
{
    int adjvex;				//�ڽӵ��򣬴洢�ö����Ӧ���±�
    struct ArcNode *next;	//����ָ����һ���ڽӵ�
}ArcNode;

typedef struct VertexNode	//�����ṹ
{
    VertexType data;		//�����򣬴洢������Ϣ
    ArcNode *firstedge;		//�߱�ͷָ��
}VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numArcs;  //ͼ�е�ǰ�������ͱ���
}ALGraph;

Status LocateVex(ALGraph *g,VertexType ch);
void CreateALGraph(ALGraph *g);
void DFS(ALGraph g,int i);
void DFSTraverse(ALGraph g);
Status GDegree(ALGraph g,int n);

#endif