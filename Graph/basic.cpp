#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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
//disconnected graph which has multiple components

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
void prepareAdjList(unordered_map<int,vector<int>> &adj,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        //undirected
        adj[v].push_back(u);
    }
}
void bfs(unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,
            vector<int> &ans,int node){
queue<int> q;
q.push(node);
visited[node]=true;
while(!q.empty()){
    int frontNode=q.front();
    q.pop();

    ans.push_back(frontNode);
    //push all adj nodes
    for(auto i:adj[frontNode]){
        if(!visited[i]){
            q.push(i);
            visited[i]=true;
        }
    }
    

}
}
void bfsTraversal(int vertex,vector<pair<int,int>> edges){
    //need a data structure to track visited or not unordered_map<node*,bool> visisted
    //queue for bfs
    // ajacency list 
    // 0->3 ,
    // 1->2,3,4
    // 2->1
    // 3-> 0,1
    // 4-> 1
    //required a visited data structure
    vector<int> ans;
    unordered_map<int,bool> visited;
    unordered_map<int,vector<int>> adj;
    prepareAdjList(adj,edges);

    //now travere all vertex or nodes if the graph has disconnected component
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    cout << "BFS Traversal: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;


}


// here code for dfs
void dfs(unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,
            vector<int> &component,int node){
                if(visited[node])return;
                component.push_back(node);
                visited[node]=true;
                for(auto i:adj[node]){
                    if(!visited[i]){
                        dfs(adj,visited,component,i);
                    }
                }
                
            }
void dfsTraversal(int V,int E,vector<vector<int>> edges){
    //prepare adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //here visited,ans, and dfs also give compoent
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    //traverse all the component
    for(int i=0;i<V;i++){
        vector<int> component;
        dfs(adj,visited,component,i);
        ans.push_back(component);
    }
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//here code for cycle detection using bfs
bool isCyclic(unordered_map<int,vector<int>> &adj,unordered_map<int ,bool> &visited,int node){
    //need queue
    //need parent to track if not parent and also visited then the cycle is present
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(node);
    parent[node]=-1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        for(auto i:adj[frontNode]){
            if(visited[i]==true && i != parent[frontNode] ){
                return true;
            }
            else if(!visited[i]){
                 visited[i]=true;
                q.push(i);
               
                parent[i]=frontNode;
            }
        }
    }
    return false;
}

void cycleDetectionBfs(int V,int E,vector<vector<int>> edges){
    //prepare a adj list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //make visited track,
    unordered_map<int,bool> visited;
    //traverse all the disconnected components
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bool ans=isCyclic(adj,visited,i);
            if(ans){
                cout<<"Cycle is Present "<<endl;
                return;
            }
        }
    }
    cout<<"Cycle  is not Present"<<endl;
}

//here code for cycle detection using dfs
bool isCyclicDfs(unordered_map<int,vector<int>> &adj,int parent,unordered_map<int,bool> &visited,int node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool present=isCyclicDfs(adj,node,visited,i);
            if(present)return true;
        }
        else if(parent!= i){
            return true;
        }
    }
}
void cycleDetectionDfs(int V,int E,vector<vector<int>> edges){
    //prepare a adj list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //make visited track,
    unordered_map<int,bool> visited;
    //traverse all the disconnected components
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bool ans=isCyclicDfs(adj,-1,visited,i);
            if(ans){
                cout<<"Cycle is Present dfs "<<endl;
                return;
            }
        }
    }
    cout<<"Cycle  is not Present dfs "<<endl;
}int main(){


    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E,vector<int>(2));
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin>>edges[i][0]>>edges[i][1];
    }

    cycleDetectionDfs(V,E, edges);


    return 0;
}