#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Status LocateVex(ALGraph *g,VertexType ch)
{
	int i;
    for(i = 0; i < MAXVEX; i++)
    {
        if(ch == g->adjList[i].data)
        {
            break;
        }
    }
    if(i >= MAXVEX)
    {
        fprintf(stderr,"there is no vertex.\n");
        return -1;
    }
    return i;
}

void CreateALGraph(ALGraph *g)
{
	int i, k, m, n;
	char p, q;
    ArcNode *e;
    ArcNode *f;
    printf("���붥�����ͱ���:");
    scanf("%d%d", &g->numVertexes, &g->numArcs);
    for(i = 0; i < g->numVertexes; i++)
    {
        printf("�����붥��%d:", i);
        g->adjList[i].data = getchar();          //���붥����Ϣ
        while(g->adjList[i].data == '\n')
        {
            g->adjList[i].data = getchar();
        }
		g->adjList[i].firstedge = NULL;          //���߱���Ϊ�ձ�
    }
    //�����߱�
    for(k = 0; k < g->numArcs; k++)
    {
        printf("�����(vi,vj)�ϵĶ������:");
//      char p, q;
        p = getchar();
        while(p == '\n')
        {
            p = getchar();
        }
        q = getchar();
        while(q == '\n')
        {
            q = getchar();
        }
//		int m, n;
        m = LocateVex(g, p);
        n = LocateVex(g, q);
        if(m == -1 || n == -1)
        {
            return;
        }
        //���ڴ�����ռ䣬���ɱ߱���
        e = (ArcNode *)malloc(sizeof(ArcNode));
        if(e == NULL)
        {
            fprintf(stderr, "malloc() error.\n");
            return;
        }
		//�ڽ����Ϊn
        e->adjvex = n;
        //��eָ��ָ��ǰ����ָ��Ľṹ
        e->next = g->adjList[m].firstedge;
        //����ǰ�����ָ��ָ��e
        g->adjList[m].firstedge = e;
        f = (ArcNode *)malloc(sizeof(ArcNode));
        if(f == NULL)
        {
            fprintf(stderr, "malloc() error.\n");
            return;
        }
		//�ڽ����Ϊm
        f->adjvex = m;
        f->next = g->adjList[n].firstedge;
        g->adjList[n].firstedge = f;
    }
}

void DFS(ALGraph g,int i)
{
    ArcNode *p;
    visited[i] = TRUE;
    printf("%c ", g.adjList[i].data);   //��ӡ���㣬Ҳ������������
    p = g.adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
        {
            DFS(g, p->adjvex);           //�Է��ʵ��ڽӶ���ݹ����
        }
        p = p->next;
    }
}

void DFSTraverse(ALGraph g)
{
	int i;
    for(i = 0; i < g.numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    for(i = 0; i < g.numVertexes; i++)
    {
		printf("����%d�Ķ���Ϊ%d\t",i,GDegree(g,i));
        if(!visited[i])
        {
            DFS(g, i);
        }
    }
}

Status GDegree(ALGraph g,int n)
{
	int i;
	int m=0;
	ArcNode an;
	for(i=0;i<g.numVertexes;++i)
	{
		an=*g.adjList[i].firstedge;
		while(an.adjvex)
		{
			m++;
			an=*an.next;
		}
	}
	return m;
}