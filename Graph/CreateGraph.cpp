// Adjacency list
#include<iostream>

typedef int EdgeData;
typedef char VertexData;
const int kNumVertices = 20;

typedef struct node{
    int adjvex;
    EdgeData edge;
    struct node * next;
}EdgeNode;

typedef struct{
    VertexData vertex;
    EdgeNode * firstedge;
}VertexNode;

typedef struct{
    VertexNode vexlist[kNumVertices];
    int num_of_vertex,num_of_edge;
} AdjGraph;


void CreatGraph(AdjGraph & G)
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
	G.vexlist[i].firstedge = NULL;
    }

    cin.get();
    cout << "请输入边,权重\n";
    int edge_head, edge_tail, weight;
    for(int i = 0; i < G.num_of_edge; i++)
    {
	cin >> edge_tail >> edge_head >> weight;

	// out edge
	EdgeNode * p = new EdgeNode;
	p->adjvex = edge_head;
	p->edge = weight;

	p->next = G.vexlist[edge_tail].firstedge;
	G.vexlist[edge_tail].firstedge = p;

	// in edge
	p = new EdgeNode;
	p->adjvex = edge_tail;
	p->edge = weight;
	
	p->next = G.vexlist[edge_head].firstedge;
	G.vexlist[edge_head].firstedge = p;
    }
}

void PrintGraph(const AdjGraph & G)
{
    for(int i = 0; i < G.num_of_vertex; i++)
    {
	std::cout << G.vexlist[i].vertex << "\t";
	for(EdgeNode * p = G.vexlist[i].firstedge; NULL != p; p = p->next)
	    std::cout << i << p->adjvex <<"|" << p->edge << "\t";
	std::cout << std::endl;
    }
}

int main()
{
    AdjGraph G;
    CreatGraph(G);
    PrintGraph(G);
}
