#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
template <typename T>
//graph has Nodes 
//graph has edges -->lines
//graph 
//Types of Graphs, cyclic,Acyclic,directed,undirected
//Undirected Graph has between 2 nodes u and v has edge
// u-v ,v-u  undirected graph
//Node is an entity to store data : edge is for connection for nodes
//degree of node --> how many edges comming toward the node is indegree
// how many edges get out form the node is outdegree
//weighted graph has weight on edges
//we have weighted undirected graph
//weight directed graph
//path--> the path doesn't end at the same node
//cyclic graph 

//graph representation adjancey matrics , adjancey list
//0->1 , 1->2 , 2->0

//adjancey matrix 2d
//0 0 1 2
//0 . 1 .
//1 . . 1
//2 1 . .


// adjancey list undirected graph
//0-1 , 1-2 , 2-0
//0-> 1 2
//1-> 0,2
//2-> 0,1

class graph{
    public:
    unordered_map<T,list<T>> adj;
    void addEdge(int u,int v,bool direction){
        //direction=0 it's mean undirected graph , else directed=1
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

vector<vector<int>> printAdjacency( int n,int m,vector<vector<int>> &edges){
     vector<vector<int>> ans(n);  // ✅ Fix: dynamic 2D vector
    for(int i=0;i<m;i++){
        //how to get u,v
        int u=edges[i][0];
        int v=edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

void bfsTraversal(){
    
}

int main(){
    // int n,m;
    // cin>>n,m;
    // graph<int> g;
    // for(int i=0;i<n;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     //making an undirected graph
    //     g.addEdge(u,v,0);
    // }
    // g.printAdj();
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(2));
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    edges=printAdjacency(n,m,edges);
   // cout<<"Done";
    for(auto i: edges){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}