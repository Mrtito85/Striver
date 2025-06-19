#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
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
}
//cycle detection in directed graph
bool dfsVis(unordered_map<int,vector<int>> adj,unordered_map<int,bool> visited,unordered_map<int,bool> dfsVisited,int node){
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool ans=dfsVis(adj,visited,dfsVisited,i);
            if(ans)return true;
        }else if(dfsVisited[i]==true){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}
void cycleDetectionDirectedGraph(int n,vector<vector<int>> edges){
    //make adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    //make visited and dfsvisited
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=dfsVis(adj,visited,dfsVisited,i);
            if(ans){
                cout<<"Present";
            }
        }
    }
    cout<<"Not preesnt";
}

//Topological sort --->  only apply in DAG
//it is linear ordering of vertices such that for every edge such that U always appear before V in ordering
void dfsCall(unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,stack<int> &s,int node){
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfsCall(adj,visited,s,i);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(int v,vector<vector<int>> &edges){
    //making an adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        //topological sort apply only DAG
        adj[u].push_back(v);
    }

    //making a visited and making stack to to check every u node appear before v
    stack<int> s;
    unordered_map<int,bool> visited;
    //traverse the disconnected components
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsCall(adj,visited,s,i);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        int element =s.top();
        ans.push_back(element);
        s.pop();
    }
    return ans;
}

//kahn's algorithm using bfs topological sort

vector<int>  kahnAlgorithm(int v,int e,vector<vector<int>> &edges){
    //make a adj list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    //calculte the indegreee for kahn's algorithm
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //if the indegree is zero then push it to the queue
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adj[frontNode]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}


//shortest path  direected Acyclic   weighted Graph
//use topological sort
//now we also have weights we consider them while making adjacency list
//new adj list unordered_map<int,list<pair<int,int>> > adj;
//6 vertix  
 //9 edges
 //0-> [1,5][2,3]
 //1->[2,2],[3,6]
 //2->[3,7],[4,4],[5,2]
 //3->[4,-1]
 //4->[5,-2]
//5->

class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>> adj;

    void addEdge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    void dfs(unordered_map<int,bool> &visited,stack<int> &s,int node){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(visited,s,i.first);
            }
        }
        s.push(node);
    }
    void getShortestPath(int src,vector<int> &distance,stack<int> &s){
        distance[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();

            if(distance[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(distance[top]+i.second <distance[i.first]){
                        distance[i.first]= distance[top]+ i.second;
                    }
                }
            }
        }
    }
};
void input1forShortestPath(){
        Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printAdj();

    //topological sort
    //make a visited array , stack for topological sort and adj list is present in graph
    unordered_map<int,bool> visited;
    stack<int> s;
    //traverse all the disconnected components
    int n=6;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(visited,s,i);
        }
    }
    
    //now prove the source node for distance array 
    int src=1;
    //now make the distance array and mark it INT_MAX
    vector<int> distance(n);
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }
    //mark the src node ditance to zero
    g.getShortestPath(src,distance,s);
    for(auto i:distance){
        cout<<i<<" ";
    }
//2147483647 0 2 6 5 3 answer is correct
}

//Dijkstra's algorithm
//shortest path to src node to all destination node
//The graph has not any negative edge contain
// vertices = 4
// edges = 5
//0->[1,5],[2,8]
//1->[0,5],[2,9],[1,3]
//2->[0,8],[1,9],[3,6]
//3->[1,2][2,6]
//distance 
//0-->0 =0
//0-->1 =5
//0-->2 =8
//0-->3 =7

//Input: src = 0, V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]] -> first node src,second destnation,third is weight

//they will give you vertices ,edges,and source node and you have to print the shortest distance to every node


int main(){




    // int v,e;
    // cin>>v>>e;
    // vector<vector<int>> edges(e,vector<int>(2));
    // cout << "Enter edges (u v):\n";
    // for (int i = 0; i <e; i++) {
    //     cin>>edges[i][0]>>edges[i][1];
    // }

    // vector<int> ans=kahnAlgorithm(v,e,edges);
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }
    // cout<<endl;


    return 0;
}