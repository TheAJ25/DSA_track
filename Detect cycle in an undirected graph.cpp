// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.




class Solution {
    
  private:
    bool isCycleDFS(vector<int> adj[], int node, vector<bool> visited, int parent){
        visited[node] = true;
        
        for(auto it : adj[node]){
            if(it == parent) continue;
            
            if(visited[it]) return true;
            
            if(isCycleDFS(adj, it, visited, node)) return true;
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, -1)){
                return true;
            }
        }
        return false;
    }
};
