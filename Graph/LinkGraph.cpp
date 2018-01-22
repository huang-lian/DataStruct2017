// 十字链表存储有向图- c语言实现
#include<iostream>

typedef int EdgeData;
typedef char VertexData;
const int kNumVertices = 20;

typedef struct Node{
    int ivex,jvex;
    struct Node * jlink;
    struct Node * ilink;
    EdgeData edge;
}EdgeNode;

typedef struct{
    VertexData vertex;
    EdgeNode * firstin;
    EdgeNode * firstout;
}VertexNode;

typedef struct {
    VertexNode vexlist[kNumVertices];
    int num_of_edge;
    int num_of_vertex;
}LinkGraph;

void CreatLinkGraph(LinkGraph & G)
{
    using std::cin;
    using std::cout;

    cout << "请输入图的顶点数和边数\n";
    cin >> G.num_of_vertex >> G.num_of_edge;

    cin.get();
    cout << "请输入顶点信息\n";
    for(int i = 0; i < G.num_of_vertex; i++)
    {
	G.vexlist[i].vertex = cin.get();
	G.vexlist[i].firstin = NULL;
	G.vexlist[i].firstout = NULL;
    }

    cin.get();
    cout << "请输入边,权重\n";
    int edge_in, edge_out, weight;
    for(int i = 0; i < G.num_of_edge; i++)
    {
	cin >> edge_out >> edge_in >> weight;

	EdgeNode * p = new EdgeNode;
	p->edge = weight;
	p->ivex = edge_out;
	p->jvex = edge_in;

	// out edge
	p->ilink = G.vexlist[edge_out].firstout;
	G.vexlist[edge_out].firstout = p;
	
	// in edge
	p->jlink = G.vexlist[edge_in].firstin;
	G.vexlist[edge_in].firstin = p;
    }
}

void PrintGraph(const LinkGraph & G)
{
    for(int i = 0; i < G.num_of_vertex; i++)
    {
	std::cout << G.vexlist[i].vertex << "\t";
	for(EdgeNode * p = G.vexlist[i].firstout; NULL != p; p = p->ilink)
	    std::cout << p->ivex << p->jvex <<"|" << p->edge << "\t";
	std::cout << std::endl;
    }
}

int main()
{
    LinkGraph G;
    CreatLinkGraph(G);
    PrintGraph(G);
}
