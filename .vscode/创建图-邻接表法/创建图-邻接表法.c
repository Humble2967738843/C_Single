#include<stdlib.h>
#include<stdio.h>

//开始
#define MaxVertexNum 100
typedef int WeightType;
typedef int DataType;
typedef struct GNode *PtrTONode;
typedef struct ENode *PtrTOEode;

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];//AdjList是邻接表类型

typedef int Vertex;//用顶点下标表示顶点，为整型
struct GNode{
    int Nv;//顶点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType data[MaxVertexNum];//存储顶点数据
};
typedef PtrTONode MGraph;//以领接矩阵存储的图类型
struct  ENode{
    Vertex V1,V2;//有向边<v1,v2>
    WeightType weight;//边的权重
};
typedef PtrTOEode Edge;
//结束


typedef int Vertex;
typedef struct GNode *PtrToNode;
struct GNode{
    int Nv;//顶点数
    int Ne;//边数
    AdjList G;//邻接表
};
typedef PtrToGNode LGraph;//以邻接表方式存储的图类型
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;//邻接点下标
    WeightType Weight;//边权重
    PtrToAdjVNode Next;
};




//初始化一个有VertexNum个顶点但没有边的图
LGraph CreateGraph(int VertexNum){
    Vertex V,W;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    //注意这里的默认顶点编号是从0开始到Graph->Nv-1
    for(V=0;V<Graph->Nv;V++){
        Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}
//向LGraph中插入边
void InsertEdge(LGraph Graph,Edge E){
    //插入边<V1,V2>
    //为V2建立新的邻接点
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;
    //将V2插入V1的表头
    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;
    //若是无向图还需要插入边<V2,V1>
    //为V1建立新的邻接点
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V1;
    NewNode->Weight=E->Weight;
    //将V1插入到V2的表头
    NewNode->Next=Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge=NewNode;
}
LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
   // Vertex V;
    int Nv,i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->weight);
            InsertEdge(Graph,E);
        }
    }
    //如果顶点有数据的话就读入数据
    /*for(V=0;V<Graph->Nv;V++){
        scanf("%c",&(Graph->data[V]));
    }*/
    return Graph;
}