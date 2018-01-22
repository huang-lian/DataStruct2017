#include<iostream>
#include<cstring>
// Adjacency Matrix
typedef char VertexData;
typedef int EdgeData;

const int kNumVertices = 20;

typedef struct {
    VertexData verlist[kNumVertices];
    EdgeData edge[kNumVertices][kNumVertices];
    int num_of_vertex;
    int num_of_edge;
}MTGraph;

void CreateMGraph(MTGraph &G)
{
    using std::cin;
    using std::cout;
    cout << "请输入图的边数和顶点数\n";
    cin >> G.num_of_edge >> G.num_of_vertex;
    cin.get();

    cout << "依次输入顶点信息(字符)\n";
    for(int i = 0; i < G.num_of_vertex; i++)
	G.verlist[i] = cin.get();
    // init
    memset(G.edge, 0 , kNumVertices * kNumVertices* sizeof(VertexData));

    int vertexi, vertexj,weight;
    cout << "依次输入边,权重\n";
    for(int i = 0; i < G.num_of_edge; i++)
    {
	cin >> vertexi >> vertexj >> weight;
	G.edge[vertexi][vertexj] = G.edge[vertexj][vertexi] = weight;
    }
}
void PrintMGraph(MTGraph & G)
{

    std::cout << "#print\n";
    for(int i = 0; i < G.num_of_vertex; i++)
	std::cout << "\t"<< G.verlist[i];
    std::cout << std::endl;
    for(int i = 0; i < G.num_of_vertex; i++)
    {
	std::cout << G.verlist[i] << "\t";
	for(int j = 0; j < G.num_of_vertex; j++)
	    std::cout << G.edge[i][j] << "\t";
	std::cout << std::endl;
    }
}

int main()
{
    MTGraph graph;
    CreateMGraph(graph);
    PrintMGraph(graph);
}

