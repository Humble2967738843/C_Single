#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef int WeightType;
typedef int DataType;
typedef struct GNode *PtrTONode;
typedef struct ENode *PtrTOEode;
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
//初始化一个有VertexNum个顶点但没有边的图
MGraph CreateGraph(int VertexNum){
    Vertex V,W;//顶点数、边数
    MGraph Graph;//创建矩阵图
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    //这里默认顶点编号从0开始，到Graph->Nv-1
    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W]=0;//或INFINTY无穷大的意思
        }
    }
    return Graph;
}
//向MGraph中插入边
void InsertEdge(MGraph Graph,Edge E){
    //插入边<V1,V2>
    Graph->G[E->V1][E->V2]=E->weight;
    //若是无向图，还要插入边<V1,V2>
    Graph->G[E->V2][E->V1]=E->weight;
    return;
}
//完整的建立一个MGraph
MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    //Vertex V;
    int Nv,i;
    printf("输入顶点数\n");
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    printf("输入边数\n");
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        printf("接下来输入V1,V2,weiht\n");
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
//第二种建立方式
/*
int G[MAXN][MAXN],Nv,Ne;
void BUildGraph(){
    int i,j,V1,V2,w;
    scanf("%d",&Nv);
    //CreateGraph
    for(i=0;i<Nv;i++){
        for(j=0;j<Nv;j++){
            G[i][j]=0;
        }
    }
    scanf("%d",&Ne);
    for(i=0;i<Ne;i++){
    scanf("%d %d %d",&V1,&V2,&w);
    //InsertEdge
    G[V1][V2]=w;
    G[V2][V1]=w;
    }
   return; 
}
*/
int main(){
    int i=0,j=0;
    MGraph MG;
    MG=BuildGraph();
   printf("邻接矩阵权值图为:\n");
    for(i=0;i<MG->Nv;i++){
        for(j=0;j<MG->Ne;j++){
            if(j%MG->Ne==0){
                printf("\n");
            }
            printf("%d ",MG->G[i][j]);
        }
    }
    printf("\n");
    printf("邻接矩阵关系图为：\n");
     for(i=0;i<MG->Nv;i++){
        for(j=0;j<MG->Ne;j++){
            if(j%MG->Ne==0){
                printf("\n");
            }
            if(MG->G[i][j]!=0){
                printf("%d ",1);
            }else{
                printf("%d ",MG->G[i][j]);
            }
        }
    }
    return 0;
}