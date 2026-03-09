#include <iostream>
using namespace std;

struct Edge {
    int start;
    int end;
    int cost;
};
int rootOf[100];
int depth[100];

int find_rootNode(int x) {
    if(rootOf[x]!=x) {
        int r=find_rootNode(rootOf[x]);
        rootOf[x]=r;
    }
    return rootOf[x];
}

void combine_sets(int a, int b) {
    int ra=find_rootNode(a);
    int rb=find_rootNode(b);
    if(ra!=rb) {
        if(depth[ra]<depth[rb]) {
            rootOf[ra]=rb;
        }
        else if(depth[ra]>depth[rb]) {
            rootOf[rb]=ra;
        }
        else {
            rootOf[rb]=ra;
            depth[ra]=depth[ra]+1;
        }
    }
}

void sortCost(Edge edges[], int nEdges) {
    for(int i=0; i<nEdges-1; i++) {
        for(int j=0; j<nEdges-i-1; j++) {
            if(edges[j].cost > edges[j + 1].cost) {
                Edge dummy=edges[j];
                edges[j]=edges[j + 1];
                edges[j + 1]=dummy;
            }
        }
    }
}

void kruskalAlg(Edge edges[], int nVertices, int nEdges) {
    sortCost(edges, nEdges);
    for(int i=0; i<nVertices; i++) {
        rootOf[i]=i;
        depth[i]=0;
    }
    int totalCost=0;
    int totalEdges=0;
    cout<<"Edges for network at minimum cost:"<< endl;
    cout<<"Edges       Cost"<< endl;

    for(int i=0; i<nEdges&&totalEdges<nVertices-1; i++) {
        int u=edges[i].start;
        int v=edges[i].end;

        if(find_rootNode(u) != find_rootNode(v)) {
            cout<< u <<" - "<< v;
            for(int j=0; j<10; j++) {
                cout<<" ";
            }
            cout<< edges[i].cost << endl;
            totalCost=totalCost+edges[i].cost;
            combine_sets(u, v);
            totalEdges++;
        }
    }
    cout<<"Total Minimum Cost: "<< totalCost << endl;
}

int main() {
    int nVertices, nEdges;
    Edge edges[100];
    cout<<"Enter the number of nodes (V): ";
    cin>> nVertices;
    cout<<"Enter the number of edges (E): ";
    cin>> nEdges;
    for(int i=0; i<nEdges; i++) {
        cout<<"Enter edge "<< i + 1 <<" (start - end - cost): ";
        cin>> edges[i].start >> edges[i].end >> edges[i].cost;
    }
    kruskalAlg(edges, nVertices, nEdges);
    return 0;
}
